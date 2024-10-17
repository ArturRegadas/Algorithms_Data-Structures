from os import system

class node:
    def __init__(self, data:int , next=None ) -> None:
        self.value = data
        self.next = next


class List:
    def __init__(self, data:int, head = None) -> None:
        self.head = node(data)
        self.listSize = 1

    def add (self, data:int) -> None:
        current = self.head
        while current.next != None:
            current = current.next
        current.next=node(data)
        self.listSize +=1


    def WriteLine(self) -> None:
        current = self.head
        while current:
            print(current.value)
            current = current.next

    def getIndex(self, index:int) -> int:
        cont = 0
        current = self.head
        while cont < index:
            current = current.next
            cont+=1
        return current



    def Insert(self, index:int, data:int)-> None:
        if index == 0 :
            TemporaryList = self.head
            self.head=node(data)
            self.head.next = TemporaryList

        elif index == self.listSize - 1:
            current = self.head
            while current.next:
                current=current.next
            current.next = node(data)

        else:
            current = self.head
            cont = 0
            while cont < index-1:
                current = current.next 
                cont += 1
            TemporaryList = current.next
            current.next = node(data)
            current.next.next=TemporaryList

        self.listSize+=1
            
    def delIndex(self, index:int) -> None:
        if index == 0:
            delete = self.head
            self.head = self.head.next
            del delete

        elif index == self.listSize - 1:
            current = self.head
            cont = 0
            while cont < index - 1:
                current = current.next
                cont+=1
            delete = current.next
            current.next = None
            del delete

        else:
            current = self.head
            cont = 0
            while cont < index -1:
                current = current.next
                cont+=1
            delete = current.next
            current.next=current.next.next
            del delete



def main() -> None:
    esc = None
    firstvalue = int(input("The first value of list: "))
    TheList = List(firstvalue)
    while esc != 'e':
        esc=input("""[a] - add
[w] - WriteLine
[g] - getIndex
[i] - insert
[d] - delete
[s] - print size
[c] - clear terminal
[e] - exit
: """)
        if esc == 'a':
            value = int(input("value to add: "))
            TheList.add(value)

        elif esc == 'w':
            TheList.WriteLine()

        elif esc == 'g':
            index = int(input("Index to get: "))
            print(TheList.getIndex(index))

        elif esc == 'i':
            value = int(input("The value to insert: "))
            index = int(input("The index to insert: "))
            TheList.Insert(index, value)
        
        elif esc == 'd':
            index = int(input("The index to delete: "))
            TheList.delIndex(index)

        elif esc == 's':
            print(TheList.listSize)
        
        elif esc == 'c':
            system("clear")

        print()


if __name__ == "__main__":
    main()





