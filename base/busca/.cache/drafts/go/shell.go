package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func in(vet []int, x int) bool {
	_ = vet
	_ = x
	return false
}

func indexOf(vet []int, x int) int {
	_ = vet
	_ = x
	return 0
}

func findIf(vet []int) int {
	_ = vet
	return 0
}

func minElement(vet []int) int {
	_ = vet
	return 0
}

func findMinIf(vet []int) int {
	_ = vet
	return 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println("$" + line)
		parts := strings.Fields(line)
		if len(parts) == 0 {
			continue
		}

		cmd := parts[0]

		switch cmd {
		case "end":
			return
		case "in":
			if len(parts) >= 3 {
				vet := str2vet(parts[1])
				val, _ := strconv.Atoi(parts[2])
				if in(vet, val) {
					fmt.Println("true")
				} else {
					fmt.Println("false")
				}
			}
		case "index_of":
			if len(parts) >= 3 {
				vet := str2vet(parts[1])
				val, _ := strconv.Atoi(parts[2])
				fmt.Println(indexOf(vet, val))
			}
		case "find_if":
			if len(parts) >= 2 {
				vet := str2vet(parts[1])
				fmt.Println(findIf(vet))
			}
		case "min_element":
			if len(parts) >= 2 {
				vet := str2vet(parts[1])
				fmt.Println(minElement(vet))
			}
		case "find_min_if":
			if len(parts) >= 2 {
				vet := str2vet(parts[1])
				fmt.Println(findMinIf(vet))
			}
		default:
			fmt.Println("fail: unknown command")
		}
	}
}

func str2vet(s string) []int {
	if s == "[]" {
		return make([]int, 0)
	}
	sub := s[1 : len(s)-1]
	tokens := strings.Split(sub, ",")
	vet := make([]int, 0, len(tokens))
	for _, token := range tokens {
		num, _ := strconv.Atoi(strings.TrimSpace(token))
		vet = append(vet, num)
	}
	return vet
}
