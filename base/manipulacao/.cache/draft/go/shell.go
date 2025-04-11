package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func getMen(vet []int) []int {
	_ = vet
	return nil
}

func getCalmWomen(vet []int) []int {
	_ = vet
	return nil
}

func sortVet(vet []int) []int {
	_ = vet
	return nil
}

func sortStress(vet []int) []int {
	_ = vet
	return nil
}

func reverse(vet []int) []int {
	_ = vet
	return nil
}

func reverseInplace(vet []int) {
	_ = vet
}
func unique(vet []int) []int {
	_ = vet
	return nil
}

func repeated(vet []int) []int {
	_ = vet
	return nil
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for {
		if !scanner.Scan() {
			break
		}
		fmt.Print("$")
		line := scanner.Text()
		args := strings.Split(line, " ")
		fmt.Println(line)

		switch args[0] {
		case "get_men":
			printVec(getMen(str2vet(args[1])))
		case "get_calm_women":
			printVec(getCalmWomen(str2vet(args[1])))
		case "sort":
			printVec(sortVet(str2vet(args[1])))
		case "sort_stress":
			printVec(sortStress(str2vet(args[1])))
		case "reverse":
			printVec(reverse(str2vet(args[1])))
		case "reverse_inplace":
			vet := str2vet(args[1])
			reverseInplace(vet)
			printVec(vet)
		case "unique":
			printVec(unique(str2vet(args[1])))
		case "repeated":
			printVec(repeated(str2vet(args[1])))
		case "end":
			return
		}
	}
}

func printVec(vet []int) {
	fmt.Print("[")
	for i, val := range vet {
		if i > 0 {
			fmt.Print(", ")
		}
		fmt.Print(val)
	}
	fmt.Println("]")
}

func str2vet(s string) []int {
	if s == "[]" {
		return nil
	}
	s = s[1 : len(s)-1]
	parts := strings.Split(s, ",")
	var vet []int
	for _, part := range parts {
		n, _ := strconv.Atoi(part)
		vet = append(vet, n)
	}
	return vet
}

