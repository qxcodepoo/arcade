package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
	"sort"
	"strconv"
	"strings"
)

func Join[T any](slice []T, sep string) string {
	result := strings.Builder{}
	for i, item := range slice {
		if i != 0 {
			result.WriteString(sep)
		}
		result.WriteString(fmt.Sprint(item))
	}
	return result.String()
}

// @DROP

func Values[K comparable, V any](m map[K]V) []V {
	vals := make([]V, 0, len(m))
	for _, v := range m {
		vals = append(vals, v)
	}
	return vals
}

// generic filter function
func Filter[T any](slice []T, predicate func(T) bool) []T {
	result := []T{}
	for _, item := range slice {
		if predicate(item) {
			result = append(result, item)
		}
	}
	return result
}

func CheckError(err error) bool {
	if err != nil {
		fmt.Println(err)
		return true
	}
	return false
}

// Fone representa um telefone com identificador e número
type Fone struct {
	ID     string
	Number string
}

// NewFone cria uma nova instância de Fone
func NewFone(id, number string) *Fone {
	return &Fone{id, number}
}

// IsValid verifica se o número de telefone é válido
func (f *Fone) IsValid() bool {
	validChars := "0123456789()-. "
	for _, c := range f.Number {
		if !strings.ContainsRune(validChars, c) {
			return false
		}
	}
	return true
}

// String retorna a representação em string do Fone
func (f *Fone) String() string {
	return fmt.Sprintf("%s:%s", f.ID, f.Number)
}

// Contact representa um contato com nome, status de favorito e uma lista de telefones
type Contact struct {
	Name      string
	Favorited bool
	Fones     []*Fone
}

// NewContact cria uma nova instância de Contact
func NewContact(name string) *Contact {
	return &Contact{name, false, []*Fone{}}
}

// AddFone adiciona um telefone ao contato
func (c *Contact) AddFone(id, number string) error {
	fone := NewFone(id, number)
	if fone.IsValid() {
		c.Fones = append(c.Fones, fone)
		return nil
	}
	return fmt.Errorf("fail: invalid number")
}

// RmFone remove um telefone do contato pelo índice
func (c *Contact) RmFone(index int) error {
	if index < 0 || index >= len(c.Fones) {
		return fmt.Errorf("fail: invalid index")
	}
	c.Fones = slices.Delete(c.Fones, index, index+1)
	return nil
}

// ToggleFavorited alterna o status de favorito do contato
func (c *Contact) ToggleFavorited() {
	c.Favorited = !c.Favorited
}

// String retorna a representação em string do Contact
func (c *Contact) String() string {
	fonesStr := []string{}
	for _, fone := range c.Fones {
		fonesStr = append(fonesStr, fone.String())
	}
	favSymbol := "-"
	if c.Favorited {
		favSymbol = "@"
	}
	return fmt.Sprintf("%s %s [%s]", favSymbol, c.Name, strings.Join(fonesStr, ", "))
}

// Agenda representa uma lista de contatos
type Agenda struct {
	Contacts map[string]*Contact
}

// NewAgenda cria uma nova instância de Agenda
func NewAgenda() *Agenda {
	return &Agenda{make(map[string]*Contact)}
}

// AddContact adiciona um novo contato ou atualiza um existente
func (a *Agenda) AddContact(name string, fones []*Fone) {
	contact, ok := a.Contacts[name]
	if !ok {
		a.Contacts[name] = NewContact(name)
		contact = a.Contacts[name]
	}
	for _, fone := range fones {
		contact.AddFone(fone.ID, fone.Number)
	}
}

func (a *Agenda) GetContact(name string) (*Contact, error) {
	contact, ok := a.Contacts[name]
	if !ok {
		return nil, fmt.Errorf("fail: contact not found")
	}
	return contact, nil

}

// RmContact remove um contato pelo nome
func (a *Agenda) RmContact(name string) error {
	_, err := a.GetContact(name)
	if err != nil {
		return err
	}
	delete(a.Contacts, name)
	return nil
}

// GetContacts retorna todos os contatos
func (a *Agenda) GetContacts() []*Contact {
	return Values(a.Contacts)
}

// GetFavorited retorna todos os contatos favoritados
func (a *Agenda) GetFavorited() []*Contact {
	favorited := func(c *Contact) bool {
		return c.Favorited
	}
	return Filter(a.GetContacts(), favorited)
}

// Search procura contatos que correspondem ao padrão
func (a *Agenda) Search(pattern string) []*Contact {
	resultados := []*Contact{}
	for _, contact := range a.Contacts {
		if strings.Contains(contact.String(), pattern) {
			resultados = append(resultados, contact)
		}
	}
	return Sorted(resultados)
}

// String retorna a representação em string da Agenda
func (a *Agenda) String() string {
	return Join(Sorted(a.GetContacts()), "\n")
}

// sortContacts ordena os contatos por nome
func Sorted(contacts []*Contact) []*Contact {
	sort.Slice(contacts, func(i, j int) bool {
		return contacts[i].Name < contacts[j].Name
	})
	return contacts
}

// @KEEP
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	// @DROP
	agenda := NewAgenda()
	// @KEEP
	for {
		fmt.Print("$")
		if !scanner.Scan() {
			break
		}
		line := scanner.Text()
		args := strings.Fields(line)
		fmt.Println(line)

		switch args[0] {
		case "end":
			return
		case "add":
			name := args[1]
			_ = name
			// @DROP
			fones := []*Fone{}
			for _, foneStr := range args[2:] {
				parts := strings.Split(foneStr, ":")
				label := parts[0]
				number := parts[1]
				fones = append(fones, NewFone(label, number))
			}
			// @DROP
			agenda.AddContact(name, fones)
		case "show":
			// @DROP
			fmt.Println(agenda.String())
		case "rmFone":
			name := args[1]
			index, _ := strconv.Atoi(args[2])
			_, _ = name, index
			// @DROP
			contact, err := agenda.GetContact(name)
			if !CheckError(err) {
				err = contact.RmFone(index)
				CheckError(err)
			}
		case "rm":
			name := args[1]
			_ = name
			// @DROP
			err := agenda.RmContact(name)
			CheckError(err)
		case "search":
			pattern := args[1]
			_ = pattern
			// @DROP
			fmt.Println(Join(agenda.Search(pattern), "\n"))
		case "tfav":
			name := args[1]
			_ = name
			// @DROP
			contact, err := agenda.GetContact(name)
			if !CheckError(err) {
				contact.ToggleFavorited()
			}
		case "favs":
			// @DROP
			fmt.Println(Join(agenda.GetFavorited(), "\n"))
		default:
			fmt.Println("fail: command not found")
		}
	}
}
