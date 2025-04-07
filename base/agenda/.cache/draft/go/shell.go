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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
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
		case "show":
		case "rmFone":
			name := args[1]
			index, _ := strconv.Atoi(args[2])
			_, _ = name, index
		case "rm":
			name := args[1]
			_ = name
		case "search":
			pattern := args[1]
			_ = pattern
		case "tfav":
			name := args[1]
			_ = name
		case "favs":
		default:
			fmt.Println("fail: command not found")
		}
	}
}
