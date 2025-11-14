# Queues

## Hello. This is C++ code that deals with Queue operations. Below are screenshots of expected outputs and error handling code.

## Menu

<img width="528" height="225" alt="Screenshot 2025-11-14 114644" src="https://github.com/user-attachments/assets/2ad9a02e-1700-4248-a24e-ccdcfc847061" />

### Creating my Queue / Pushing Elements / Queue Function Menu
Below I create a queue by deciding first what data type I want the elements to be. I continued with a string queue and added "Sam" , "Adam" , "John" , and "Frank"

<img width="448" height="314" alt="Screenshot 2025-11-14 114800" src="https://github.com/user-attachments/assets/a13f5cc5-d0fb-4d8f-bc61-dd4ea3331f7b" />

<img width="436" height="56" alt="Screenshot 2025-11-14 120010" src="https://github.com/user-attachments/assets/9d6d09ad-9116-4434-83f8-3e5eba7b3b26" />

### Popping Elements
Option 2 lets up pop an element. Popping an element take the front of the queue out. Since "Sam" is in the beginning, he will be the first to be popped out.

<img width="265" height="47" alt="Screenshot 2025-11-14 114901" src="https://github.com/user-attachments/assets/d5564ff9-1afa-4edd-a9f9-493f354a2e7e" />

### View Front
Option 3 let's us know who/what is in the front of the queue.

<img width="221" height="49" alt="Screenshot 2025-11-14 114924" src="https://github.com/user-attachments/assets/d61a2da3-54ce-4efe-9605-63568c719342" />

### Display Queue / Show Size
Option 4 displays the current Queue.

<img width="390" height="51" alt="Screenshot 2025-11-14 114912" src="https://github.com/user-attachments/assets/e2802a80-287c-4d44-a062-303fdbed9ee6" />

### Show Size
Option 5 tells how many elements are in our queue.

<img width="213" height="46" alt="Screenshot 2025-11-14 114938" src="https://github.com/user-attachments/assets/bd45597b-fd67-42f6-ad84-d8d762bfded5" />

### Is Empty?
Option 6 will tell us if the queue is empty or not. In this case it will not be empty.

<img width="226" height="49" alt="Screenshot 2025-11-14 120625" src="https://github.com/user-attachments/assets/d98f10b6-88ab-422e-94e8-c5d58efa8802" />

### Move the Front Element to the Rear
Option 7 let's us move the front of the queue to the back. Since "Adam" is currently in the front, using this fucntion will put him all the way to the end and "Frank" will be the new element in the front.

### Clear Queue
Option 8 lets me clear the queue. Not part of the assignment but added for ease of testing.

<img width="211" height="49" alt="Screenshot 2025-11-14 115019" src="https://github.com/user-attachments/assets/6a5aa1e1-912c-436c-8431-658682a4d1eb" />

## Recursive Linear Search
Going back to the very first menu, clicking on option 5 lets us demo a Recursive Linear Search. The program will ask us to input the size of elements we want in the vector and then we continue on to add the integers we want. Then we enter a target value and the function will find where it's last occurence is within the vector.

<img width="625" height="145" alt="Screenshot 2025-11-14 115127" src="https://github.com/user-attachments/assets/5e716e10-75d6-4f71-8b01-7689d77f41ce" />

## Insertion Sort
Again back at the first menu, we are given the option to also demo an Insertion Sort fucntion by clicking on option 6. This will also prompt the us with how many elements we want in this list and continue on to add the integers we want. When we add those integers (in any order), it will display a sorted list in ascending order.

<img width="450" height="214" alt="Screenshot 2025-11-14 115454" src="https://github.com/user-attachments/assets/55e7f84d-8a99-4ef6-a27a-92e199ceeb9b" />

## Error Handling
### Below are a few example errors that could occur during use.

### Wrong Data type
Below, the user is trying to input a string into a queue that already has (Integers) as it's chosen data type. To fix, go back to the type menu and choose the correct data type.

<img width="435" height="308" alt="Screenshot 2025-11-14 115640" src="https://github.com/user-attachments/assets/6c6ec764-bcd7-4bb4-a257-83409b08c14f" />

### Front on Empty Queue
Below, the user is trying to view the front of an empty queue. To fix, add elements into the queue.

<img width="610" height="283" alt="Screenshot 2025-11-14 115658" src="https://github.com/user-attachments/assets/3e3d7cbf-0479-44d1-8e1f-62a0f3409ba7" />
