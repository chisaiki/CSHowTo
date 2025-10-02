Even if head_ points to a valid node, head_->next == nullptr just means there's only one element, not that the stack is empty

```
//Wrong
bool isEmpty(){
    return (size_ == 0 && head_->next == nullptr);
}

// If stack is empty:
head_ == nullptr
head_->next  // ← CRASH! You're dereferencing a null pointer

//---------

// If stack has ONE element:
head_ != nullptr (points to the element)
head_->next == nullptr  // ← This is true, but stack is NOT empty!

// Your function would say: "size is 0 AND head_->next is null"
// But if there's one element, size should be 1, not 0!
```

I forgot to initalize the constructor:
```
/usr/bin/ld: /tmp/cckwVjZ2.o: in function `main':
main.cpp:(.text+0x23): undefined reference to `Stack<int>::Stack()'
collect2: error: ld returned 1 exit status

Fix: Fill in the body
```