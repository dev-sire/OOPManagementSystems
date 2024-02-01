#include<iostream>
#define MAX_BOOK_LIMIT 100
#define MAX_TITLE_LEN 256
#define MAX_AUTHOR_LEN 128 
#define MAX_ISBN_LEN 16 

using namespace std;
class Book{
	string title, author, isbn;
	bool availability;
public:
	void SetTitle(string pTitle){
		title = pTitle;
	}	
	void SetAuthor(string pAuthor){
		author = pAuthor;
	}
	void SetISBN(string pIsbn){
		isbn = pIsbn;
	}
	void SetAvailable(bool pAvailable){
		availability = pAvailable;
	}
	string GetTitle(){
		return title;
	}
	string GetAuthor(){
		return author;
	}
	string GetISBN(){
		return isbn;
	}
	bool getAvailable(){
		if(this-> availability){
			return true;	
		}
		else{
			return false;
		}
	}		
};
void add(int &count, Book *bookObjs){ 
 int i = 0; 
 char inTitle[MAX_TITLE_LEN], inAuthor[MAX_AUTHOR_LEN], inISBN[MAX_ISBN_LEN]; 
 while (i < MAX_BOOK_LIMIT){ 
 	if (bookObjs[count].getAvailable() == false){
		  	cout << "Enter book title:" << endl; 
		  	cin.getline(inTitle,MAX_TITLE_LEN);
	        cout << "Enter book author:" << endl;
	        cin.getline(inAuthor,MAX_AUTHOR_LEN);
	        cout << "Enter book ISBN:" << endl;
	        cin.getline(inISBN,MAX_ISBN_LEN);
	        bookObjs[count].SetTitle(inTitle);
	        bookObjs[count].SetAuthor(inAuthor);
	        bookObjs[count].SetISBN(inISBN);
	        bookObjs[count].SetAvailable(true);
	        cout << "Book added to library." << endl;
	        count++;
	        break;
    	}
    	else
        	i++;
	}
}
void remove(int &count, Book *bookObjs){ 
	int i = 0; 
	char inISBN[MAX_ISBN_LEN]; 
	cout << "Enter the isbn of the book to be removed:" << endl; 
	cin.getline(inISBN, MAX_ISBN_LEN); 
	while(i < MAX_BOOK_LIMIT){ 
		if (bookObjs[i].GetISBN() == inISBN){ 
			#if 0 
			bookObjs[i].SetTitle(""); 
			bookObjs[i].SetAuthor(""); 
			bookObjs[i].SetISBN(""); 
			count--; 
		#endif 
		if(bookObjs[i].getAvailable() == true){ 
			bookObjs[i].SetAvailable(false); 
			cout << "Book removed from library." << endl; 
		} 
		else 
		 cout << "Book is already checked out" << endl;
		break; 
		} 
		else 
			i++; 
	} 
}
void searchByKeyValue(int &count, Book *bookObjs, string key, string value){ 
	int i = 0; 
	while(i < MAX_BOOK_LIMIT){ 
		if(key == "ISBN"){ 
			if (bookObjs[i].GetISBN() == value){ 
				cout << "Book Information:" << endl; 
				cout << "Title: " << bookObjs[i].GetTitle() << endl; 
				cout << "Author: " << bookObjs[i].GetAuthor() << endl; 
				cout << "ISBN: " << bookObjs[i].GetISBN() << endl; 
				cout << "Availability: " << bookObjs[i].getAvailable() << endl; 
				break; 
			} 
			else i++; 
		} 
		else if(key == "AUTHOR"){ 
			if(bookObjs[i].GetAuthor() == value){ 
				cout << "Book Information:" << endl; 
				cout << "Title: " << bookObjs[i].GetTitle() << endl; 
				cout << "Author: " << bookObjs[i].GetAuthor() << endl; 
				cout << "ISBN: " << bookObjs[i].GetISBN() << endl; 
				cout << "Availability: " << bookObjs[i].getAvailable() << endl; 
				break; 
			} 
			else i++; 
		} 
		else{ 
			if(bookObjs[i].GetTitle() == value){ 
				cout << "Book Information:" << endl; 
				cout << "Title: " << bookObjs[i].GetTitle() << endl; 
				cout << "Author: " << bookObjs[i].GetAuthor() << endl; 
				cout << "ISBN: " << bookObjs[i].GetISBN() << endl; 
				cout << "Availability: " << bookObjs[i].getAvailable() << endl; 
				break; 
			} 
			else i++; 
		} 
	}
}
void search(int &count, Book *bookObjs){ 
	char inTitle[MAX_TITLE_LEN], inAuthor[MAX_AUTHOR_LEN], inISBN[MAX_ISBN_LEN]; 
	int choice; 
	cout << "Enter the option to search by 1. title / 2. author / 3. ISBN: " << endl; 
	cin >> choice; 
	cin.ignore(); 
	switch(choice){ 
		case 1:  
			cout << "Enter the title of the book to be searched:" << endl; 
			cin.getline(inTitle, MAX_TITLE_LEN); 
			searchByKeyValue(count, bookObjs, "TITLE", inTitle); 
		break;
    	case 2:
            cout << "Enter the author of the book to be searched:" << endl;
            cin.getline(inAuthor, MAX_AUTHOR_LEN);
            searchByKeyValue(count, bookObjs, "AUTHOR", inAuthor);
        break;
    	case 3:
            cout << "Enter the isbn of the book to be searched:" << endl;
            cin.getline(inISBN, MAX_ISBN_LEN);
            searchByKeyValue(count, bookObjs, "ISBN",inISBN);
        break;
    	default:
            cout << "Wrong choice skipping search()" << endl;
	}
}
int main(){
	Book* myBookObjs = new Book[MAX_BOOK_LIMIT];
	int counter = 0, choice;
	bool continuepgrm = true;
	for (int i = 0 ; i < MAX_BOOK_LIMIT; i++){
    	myBookObjs[i].SetAvailable(false);
	}
	cout << "Welcome to the library management system!" << endl;
	while(continuepgrm){
    cout << "Menu:" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Search a book" << endl;
    cout << "4. Exit the library management system" << endl;
    cout << endl << "Enter your choice:" << endl;
    cin >> choice;
    cin.ignore();
    switch(choice){
        case 1:
            if (counter == MAX_BOOK_LIMIT){
                cout << "Library if full. No Space left to add new book entry!" << endl;
            }
            else
                add(counter, myBookObjs);
        	break;
        case 2:
            remove(counter, myBookObjs);
            break;
        case 3:
	        search(counter, myBookObjs);
            break;
        case 4:
            continuepgrm = false;
            cout << "Thank you for using the Library Management System!" << endl;
            break;
        default:
            cout << "Bad choice, re-enter the choice again!!" << endl;
    	}
	}
	delete[] myBookObjs;
	return 0;
}