class Stack {
private:
    int arr[100];
    int top;  // This is an *index*, not the value itself

public:
    Stack() {
        top = -1;  // Empty stack
    }

    void push(int val) {
        arr[++top] = val;
    }

    void pop() {
        if (top >= 0) top--;
    }

    int peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};
