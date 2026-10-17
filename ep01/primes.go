package main
import "fmt"
func main(){for n:=2;n<100;n++{i:=2;for n%i!=0{i++};if i==n{fmt.Printf("%d ",n)}}}