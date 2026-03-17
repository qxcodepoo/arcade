import argparse
import base64
import json
import os
import sys

# Função de codificação (Encode)
def encode_image(image_path: str, json_path: str):
    """Lê um arquivo de imagem, codifica para Base64, e salva em um JSON."""
    
    # 1. Obter o tipo MIME e o nome do arquivo original
    file_extension = os.path.splitext(image_path)[1].lower()
    
    # Mapeamento de extensões para tipos MIME
    if file_extension in ('.webp', '.jpeg'):
        mime_type = 'image/jpeg'
    elif file_extension == '.webp':
        mime_type = 'image/png'
    else:
        print(f"ERRO: Formato de imagem '{file_extension}' não suportado (apenas .webp ou .webp).")
        sys.exit(1)

    try:
        # 2. Ler o arquivo binário da imagem
        with open(image_path, "rb") as image_file:
            # 3. Codificar os bytes para Base64
            encoded_string = base64.b64encode(image_file.read()).decode('utf-8')
        
        # 4. Criar o Data URI e o objeto JSON
        # O Data URI (string) é a forma padrão de incorporar Base64 em ambientes web/JSON
        data_uri = f"data:{mime_type};base64,{encoded_string}"
        
        # Nome do arquivo original para uso no decode
        original_filename = os.path.basename(image_path) 
        
        json_data = {
            "file_name": original_filename,
            "mime_type": mime_type,
            "base64_data": encoded_string
        }
        
        # 5. Salvar o JSON
        with open(json_path, "w") as json_file:
            json.dump(json_data, json_file, indent=4)
            
        print(f"✅ Sucesso: Arquivo '{image_path}' codificado e salvo em '{json_path}'.")
        print(f"   Tamanho original: {os.path.getsize(image_path)/1024:.2f} KB")
        print(f"   Tamanho do JSON: {os.path.getsize(json_path)/1024:.2f} KB")


    except FileNotFoundError:
        print(f"ERRO: Arquivo de imagem não encontrado em '{image_path}'")
        sys.exit(1)
    except Exception as e:
        print(f"ERRO ao codificar: {e}")
        sys.exit(1)

# Função de decodificação (Decode)
def decode_image(json_path: str):
    """Lê um arquivo JSON, decodifica o Base64, e salva o arquivo original."""
    try:
        # 1. Ler o JSON
        with open(json_path, "r") as json_file:
            json_data = json.load(json_file)
            
        # 2. Extrair dados
        encoded_string = json_data.get("base64_data")
        original_filename = json_data.get("file_name", "decoded_image.bin") # Fallback
        
        if not encoded_string:
            print("ERRO: O arquivo JSON não contém a chave 'base64_data'.")
            sys.exit(1)
            
        # 3. Decodificar o Base64 de volta para bytes
        image_bytes = base64.b64decode(encoded_string.encode('utf-8'))
        
        # 4. Salvar os bytes como o arquivo original
        with open(original_filename, "wb") as image_file:
            image_file.write(image_bytes)
            
        print(f"✅ Sucesso: Arquivo '{json_path}' decodificado e salvo como '{original_filename}'.")
        print(f"   Tamanho do arquivo decodificado: {os.path.getsize(original_filename)/1024:.2f} KB")

    except FileNotFoundError:
        print(f"ERRO: Arquivo JSON não encontrado em '{json_path}'")
        sys.exit(1)
    except json.JSONDecodeError:
        print(f"ERRO: Não foi possível ler o JSON em '{json_path}'. Verifique o formato.")
        sys.exit(1)
    except Exception as e:
        print(f"ERRO ao decodificar: {e}")
        sys.exit(1)


# Configuração do ArgumentParser para subcomandos
def main():
    parser = argparse.ArgumentParser(
        description="Ferramenta para codificar imagens em Base64 dentro de JSONs e decodificar de volta."
    )
    # Cria o objeto para gerenciar os subcomandos (encode, decode)
    subparsers = parser.add_subparsers(dest="command", required=True)

    # --- Subcomando ENCODE ---
    parser_encode = subparsers.add_parser("encode", help="Codifica uma imagem para Base64 e salva em um JSON.")
    parser_encode.add_argument("image_file", type=str, help="Caminho para o arquivo de imagem (ex: foto.webp).")
    parser_encode.add_argument("json_output", type=str, help="Caminho para o arquivo JSON de saída (ex: dados.json).")
    parser_encode.set_defaults(func=lambda args: encode_image(args.image_file, args.json_output))

    # --- Subcomando DECODE ---
    parser_decode = subparsers.add_parser("decode", help="Decodifica um JSON contendo Base64 e salva como arquivo de imagem.")
    parser_decode.add_argument("json_file", type=str, help="Caminho para o arquivo JSON de entrada (ex: dados.json).")
    parser_decode.set_defaults(func=lambda args: decode_image(args.json_file))

    # Analisar argumentos e chamar a função correspondente
    if len(sys.argv) == 1:
        parser.print_help(sys.stderr)
        sys.exit(1)

    args = parser.parse_args()
    args.func(args)

if __name__ == "__main__":
    main()