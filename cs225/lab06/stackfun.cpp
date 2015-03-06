
// sum
// adds all the elements in a stack
template <typename T>
T StackFun::sum(stack<T> & s)
{
    T temp1;                // temp1 holds top of stack
    T temp2;                // temp2 holds sum of stack without top
    if(!s.empty()) {        // if statement returns 0 if stack is empty
        temp1=s.top();      // save top of stack before popped
        s.pop();
        temp2= sum(s);      // recursively call stack below top
        s.push(temp1);      // restore top of stack
        return (temp1+temp2); // return sum of top + sum below top
    }
    return 0;              // return 0 if stack is empty
}

// scramble
// reorders even sized blocks of items in the queue
// blocks start at size one and increases for each subsequent block
template <typename T>
void StackFun::scramble(queue<T> & q)
{
    stack<T> s;                // temporary stack
    int counter=q.size();      // counter to track progress navigating q
    int k=1;                   // counter to know how many items scrambling
    int i;                     // counter for loop

    while (counter != 0) {       // exits once function cycles through q

    for (i=0; ((i<k)&&(counter!=0)); i++) {  // only runs if counter isn't 0
        if (k%2) {                           // executes nonscramble on odd k
            q.push(q.front());
        }
        else {                               // executes scramble if k is even
            s.push(q.front());               // pushes q.front to top
        }
        q.pop();                             // pops q as it is either in right location
                                             // or saved in s
        counter=counter-1;                   // decrement counter
    }
   while (!s.empty()) {                      // copies over scrambled
        q.push(s.top());                     // push top of stack to queue
        s.pop();                             // pop top element of temp stack
    }
    k=k+1;                                   // increment k

    }
    
}

// verifySame
template <typename T>
bool StackFun::verifySame(stack<T> & s, queue<T> & q)
{
    bool retval = true; // optional
    T temp21; // rename me
    T temp22; // rename :)
    
    return retval;
}

