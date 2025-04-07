package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)


func main() {
	scanner := bufio.NewScanner(os.Stdin)
	market := NewMarket(3)

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
			fmt.Println(market.String())
		case "init":
			qtd, _ := strconv.Atoi(parts[1])
		case "arrive":
			name := parts[1]
		case "call":
			index, _ := strconv.Atoi(parts[1])

		case "finish":
			if len(parts) < 2 {
				fmt.Println("fail: índice não informado")
				continue
			}
			index, _ := strconv.Atoi(parts[1])
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
