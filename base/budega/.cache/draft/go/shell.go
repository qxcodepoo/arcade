package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

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
		case "init":
			qtd, _ := strconv.Atoi(parts[1])
			_ = qtd
		case "arrive":
			name := parts[1]
			_ = name
		case "call":
			index, _ := strconv.Atoi(parts[1])
			_ = index
		case "finish":
			index, _ := strconv.Atoi(parts[1])
			_ = index
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
