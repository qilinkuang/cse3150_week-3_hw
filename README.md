When it comes to pointers and references, a good example would be in changing a student's gpa, rather than creating new copies of the information. In case 2, the pointer to student gpa allows me to read the value, and when I go within the class updateGPA, it dereferences the pointer it receives and can re-assign a value at the address.


When printing students' names, the name is set to const, as those should not be changed within the function.


In averageGPA, I casted gpa into an int before the print statements, so it rounds up to a whole number.


For exceptions, I used throw and catch in multiple functions, for example, in addStudent, it used throw "List full" on the occasion that the user wants to add more students when the capacity has been reached. Then, in case 1, if the size is greater than or equal to the capacity, then it will throw the message within addStudent, and it will be caught and printed out.


If statements were mainly used for control flow in cases, that is, if and or like in whether or not there is space for a new student or if a student exists. A for loop at the end to free the memory.

