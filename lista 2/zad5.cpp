void reverse(lnode*& L) {
	if (L) {//dopuki istnieje element tablicy
		
		lnode* current = L;
		lnode* next = NULL;
		lnode* prev = NULL;

		while (current != NULL) {
			next = current -> next;//przypisany wskaźnik na następny element listy
			current -> next = prev;//odwraca wskażnik ustawiając go na prev
			prev = current;//przechodzimy do następnego elementu
			current = next;//przechodzimy do kolejnego elementu 
		}
		L = prev;//odwrócenie wskaźnika na nowy element który jest pierwszy
	}
}

