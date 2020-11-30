package main

import (
	"fmt"
)

var luckyNumbers []uint16 = []uint16{
	4, 7,
	44, 47, 74, 77,
	444, 447, 477, 744, 774, 777,
}

func main() {
	var input uint16
	var lucky bool

	fmt.Print("Bir sayı giriniz: ")
	_, _ = fmt.Scan(&input)

	for _, i := range luckyNumbers {
		if input%i == 0 {
			lucky = true
			break
		}
	}

	fmt.Println(func() string {
		if lucky {
			return "Yes"
		}
		return "No"
	}())
}
