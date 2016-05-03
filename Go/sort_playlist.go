package main

import "fmt"

func main() {
	var items int
	fmt.Scanf("%d", &items)

	var slice = make([]int, items)
	for i := 0; i < items; i++ {
		fmt.Scanf("%d", &slice[i])
	}

	counter := 0
	var temp int

	for x := 0; x < items; x++ {
		for i := 0; (i + 1) < items; i++ {
			if slice[i] > slice[i+1] {
				temp = slice[i]
				slice[i] = slice[i+1]
				slice[i+1] = temp

				counter++
			}
		}
	}

	fmt.Print(counter)
}
