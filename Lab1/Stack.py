class Stack:
    
    class _Node:
        __slots__ = ("val","next") #for memory slots 
        def __init__(self,val, next = None):
            self.val = val
            self.next = next 

    def __init__(self):
        self.head = None  
        self.n = 0
        self.stack 

    def push(self, x):
        self.head = self._Node(x,self.head)
        self.n += 1 

    def top(self):
        if self.head is None:
            raise IndexError("empty stack")

    def pop(self):
        if self.head is None:
            raise IndexError("Pop from empty stack")
        else:
            node = self.head 
            self.head = node.next
            self.n -= 1

    def empty(self):
        return self.head is None