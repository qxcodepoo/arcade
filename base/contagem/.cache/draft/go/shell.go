package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func count(vet []int, x int) int {
	_ = vet
	_ = x
	return 0
}

func sum(vet []int) int {
	_ = vet
	return 0
}

func average(vet []int) float64 {
	return 0
}

func moreMen(vet []int) string {
	_ = vet
	return ""
}

func halfCompare(vet []int) string {
	_ = vet
	return ""
}

func sexBattle(vet []int) string {
	_ = vet
	return ""
}

// Funções auxiliares

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fmt.Printf("$%s\n", line)
		args := strings.Fields(line)
		if len(args) == 0 {
			continue
		}

		switch args[0] {
		case "end":
			return
		case "count":
			fmt.Println(count(str2vet(args[1]), toInt(args[2])))
		case "sum":
			fmt.Println(sum(str2vet(args[1])))
		case "average":
			fmt.Printf("%.2f\n", average(str2vet(args[1])))
		case "more_men":
			fmt.Println(moreMen(str2vet(args[1])))
		case "half_compare":
			fmt.Println(halfCompare(str2vet(args[1])))
		case "sex_battle":
			fmt.Println(sexBattle(str2vet(args[1])))
		default:
			fmt.Println("fail: unknown command")
		}
	}
}

func str2vet(s string) []int {
	sub := s[1 : len(s)-1]
	parts := strings.Split(sub, ",")
	var vet []int
	for _, part := range parts {
		if part == "" {
			continue
		}
		val, _ := strconv.Atoi(part)
		vet = append(vet, val)
	}
	return vet
}

func toInt(s string) int {
	val, _ := strconv.Atoi(s)
	return val
}
