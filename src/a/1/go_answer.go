package main

import (
	"fmt"
	"sync"
)

var luckyNumbers []uint16 = []uint16{
	4, 7,
	44, 47, 74, 77,
	444, 447, 477, 744, 774, 777,
}

func main() {
	var wg sync.WaitGroup
	var input uint16
	var lucky bool

	fmt.Print("Bir sayı giriniz: ")
	_, _ = fmt.Scan(&input)

	wg.Add(len(luckyNumbers))

	for _, i := range luckyNumbers {
		go func(i uint16) {
			defer wg.Done()
			if i%input == 0 {
				lucky = true
			}
		}(i)
	}

	wg.Wait()

	fmt.Println(func(lucky bool) string {
		if lucky {
			return "Yes"
		}
		return "No"
	}(lucky))
}
