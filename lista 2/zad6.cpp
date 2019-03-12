
int counter = 0;

lnode* merge(lnode* L1, lnode* L2) {
	lnode* resultL = NULL;//tworzymy pusty result 
	if (L1 == NULL) { //jeżeli lista jest pusta zwróc l2
		counter++;
		return (L2);
	} 
	if (L2 == NULL) {
		counter++;
		return (L1);
	}

	if (L1 -> key <= L2 -> key) {// jeżeli 1 klucz jest <= kluczowi z drugiej
		resultL = L1; // jeżeli 1 lista(klucz) jest mniejsza lub równa 2 to daj na początke drugiej
		resultL -> next = merge(L1 -> next, L2);//przypisz resoult do next i zrób na nim mearge
	} else {
		resultL = L2;
		resultL -> next = merge(L1, L2 -> next);
	}
	counter++;
	return (resultL);
}

