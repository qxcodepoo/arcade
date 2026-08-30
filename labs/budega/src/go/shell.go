package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// @DROP

type Person struct {
	name string
}

func NewPerson(name string) *Person {
	return &Person{name}
}

func (p *Person) GetName() string {
	return p.name
}

func (p *Person) SetName(name string) {
	p.name = name
}

type Market struct {
	caixas []*Person
	espera []*Person
}

func NewMarket(nCaixas int) *Market {
	return &Market{
		caixas: make([]*Person, nCaixas),
		espera: []*Person{},
	}
}

func (m *Market) Chegar(pessoa *Person) {
	m.espera = append(m.espera, pessoa)
}

func (m *Market) Chamar(index int) error {
	if len(m.espera) == 0 {
		return fmt.Errorf("fail: sem clientes")
	}
	if index < 0 || index >= len(m.caixas) {
		return fmt.Errorf("fail: caixa inexistente")
	}
	if m.caixas[index] != nil {
		return fmt.Errorf("fail: caixa ocupado")
	}
	m.caixas[index] = m.espera[0]
	m.espera = m.espera[1:]
	return nil
}

func (m *Market) Finalizar(index int) error {
	if index < 0 || index >= len(m.caixas) {
		return fmt.Errorf("fail: caixa inexistente")
	}
	if m.caixas[index] == nil {
		return fmt.Errorf("fail: caixa vazio")
	}
	m.caixas[index] = nil
	return nil
}

func (m *Market) String() string {
	caixas := []string{}
	for _, p := range m.caixas {
		if p == nil {
			caixas = append(caixas, "-----")
		} else {
			caixas = append(caixas, p.GetName())
		}
	}
	espera := []string{}
	for _, p := range m.espera {
		espera = append(espera, p.GetName())
	}
	return fmt.Sprintf("Caixas: [%s]\nEspera: [%s]", strings.Join(caixas, ", "), strings.Join(espera, ", "))
}

// @KEEP
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	// @DROP
	market := NewMarket(3)
	// @KEEP

	for {
		if !scanner.Scan() { // read line and store in scanner buffer
			break
		}
		line := scanner.Text() // get the line from the scanner buffer into a string
		fmt.Println("$" + line)

		parts := strings.Fields(line)
		cmd := parts[0]

		switch cmd {
		case "end":
			break
		case "show":
			// @DROP
			fmt.Println(market.String())
		case "init":
			qtd, _ := strconv.Atoi(parts[1])
			_ = qtd
			// @DROP
			market = NewMarket(qtd)
		case "arrive":
			name := parts[1]
			_ = name
			// @DROP
			market.Chegar(NewPerson(name))
		case "call":
			index, _ := strconv.Atoi(parts[1])
			_ = index
			// @DROP
			if err := market.Chamar(index); err != nil {
				fmt.Println(err)
			}
		case "finish":
			index, _ := strconv.Atoi(parts[1])
			_ = index
			// @DROP
			if err := market.Finalizar(index); err != nil {
				fmt.Println(err)
			}
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
