// Samet BELLUR
// Çift Yönlü Baðlý Liste ve Fonksiyonlarý

#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int data;//veri
	struct node *next;// Sonraki Düðüm Ýþaretçisi
	struct node *prev;// Önceki Düðüm Ýþaretçisi
};

struct node * start = NULL;//Ýlk düðümü bilmeliyiz

struct node* makenode (int idata){ //Bu fonksiyon düðüm üretir, ("idata" incoming data yani gelen veri anlamýnda)
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data= idata;
	newnode->next= NULL;
	newnode->prev= NULL;
	
	return(newnode);
}

void addToFirst (int idata){//Bu fonksiyon baþtan düðüm ekler ("idata" anlamý incoming data yani gelen veri dir)
    struct node * willBeAdded = makenode (idata);//Düðüm oluþturup atadýk ("willBeAdded" eklenecek düðüm anlamýnda)
    
    if (start == NULL){//Bunun eklenen ilk düðüm olup olmadýðýný kontrol etmeliyiz
		start= willBeAdded;
		printf("---EKLENDI---\n");
	}
	else {
		start->prev= willBeAdded;
		willBeAdded->next= start;
		start= willBeAdded;
		}
	system ("pause");
	system ("cls");
}

void addToLast (int idata){//Bu fonksiyon sondan düðüm ekler ("idata" anlamý incoming data yani gelen veri dir)
	struct node * willBeAdded = makenode (idata);//Düðüm oluþturup atadýk ("willBeAdded" eklenecek düðüm anlamýnda)
	
	if (start == NULL){//Bunun eklenen ilk düðüm olup olmadýðýný kontrol etmeliyiz
		start= willBeAdded;
		printf("---EKLENDI---\n");
	}
	else {//Eðer bu eklenecek ilk düðüm deðilse, son düðümü bulmalýyýz
		
		struct node * temp = start;//Listede olaþým için geçici iþaretçi
		
		while (temp->next !=NULL){//Bu döngü sonucunda bize son düðümü verir
			temp= temp->next;
		}
		
		willBeAdded->prev = temp;//Yeni düðümün önceki iþaretçisine bulduðumuz son düðümü atarýz
		temp->next= willBeAdded;//Bulduðumuz son düðümün sonraki iþaretçisine de yeni düðümü atarýz
		printf("---EKLENDI---\n");
		
	}
	system ("pause");
	system ("cls");
}

struct node* searchNode (int sdata){//Bu fonksiyon düðüm arar ("sdata" search data yani aranacak veridir)
    if (start==NULL){//Listenin doluluðunu kontrol etmemiz gerekli
		system ("cls");
		printf("Liste Bos\n");
		system ("pause");
		system ("cls");
		return;
	}
	struct node * temp = start;//Listede olaþým için geçici iþaretçi
	while (temp->next != NULL){
		if (temp->data == sdata){//Bu döngü son düðüme kadar kontrol eder ama son düðüm bu aramaya dahil deðildir
			system("cls");
			printf("---Dugum Bulundu: %d---\n",temp->data);
			system("pause");
			system ("cls");
			return (temp);
		}
		temp= temp->next;
	}
	if (temp->data== sdata){//Son düðümü kontrol ederiz
		    system("cls");
			printf("---Dugum Bulundu: %d---\n",temp->data);
			system("pause");
			system ("cls");
			return (temp);
	}
	printf("\nVeri Listelenmemis!!\n");
	system("pause");
	system ("cls");
}

void insertion (int sdata,int idata){//Araya ekleme fonksiyou (girilen deðerin öncesine) ("sdata" search data yani aranacak veridir)

    struct node * temp = start;//Arama için geçici iþaretçi
    struct node * willBeAdded= makenode (idata);//Düðüm oluþturup atadýk ("willBeAdded" eklenecek düðüm anlamýnda)
    struct node * previousNode= NULL;//Araya ekleme için gerekli geçici iþaretçi ("previousNode" önceki düðüm anlamýnda)
    
	temp= searchNode (sdata);
    previousNode= temp->prev;
	
	if (previousNode==NULL){//Kullanýcýnýn ilk düðümün öncesine ekleme yapmaya çalýþýp çalýþmadýðýný kontrol etmeliyiz.
		addToFirst(idata);
	}
	else{// eðer ilk düðüm deðilse devam edebiliriz
    temp->prev= willBeAdded;
    willBeAdded->next = temp;
    willBeAdded->prev= previousNode;
    previousNode->next = willBeAdded;
	}
	printf("---%d den Once Araya %d Eklendi---\n",temp->data,idata);
	system ("pause");
	system ("cls");
}

void deleteNode (int sdata){//Bu fonksiyon düðüm siler
	if (start==NULL){//Listenin doluluðunu kontrol etmemiz gerekli
		system ("cls");
		printf("Liste Bos\n");
		system ("pause");
		system ("cls");
	}
	else {
	struct node * temp = NULL;//Arama için geçici iþaretçi
	temp = searchNode(sdata);
	if (temp==NULL){}//Listede aranan verinin bulunmama ihtimali
	else{
	struct node * nextNode = temp->next;//Silme iþlemi için iþaretçi ("nextNode" sonraki düðüm anlamýnda)
	struct node * previousNode = temp->prev;//Silme iþlemi için iþaretçi ("previousNode" önceki düðüm anlamýnda)
	   if (previousNode==NULL && nextNode==NULL){//Listede 1 veri olma ihtimalini kontrol etmeliyiz
		free(start);
	   	start= NULL;	
	   }
	   else if (previousNode==NULL){//Kullanýcýnýn ilk düðümü silmek isteyip istemediðini kontrol etmeliyiz
	    struct node * secondNode = temp->next;//Listedeki 2. Düðüm
		free(temp);
		secondNode->prev= NULL;
		start= secondNode;	
	   }
	   else if (nextNode==NULL){//Kullanýcýnýn son düðümü silmek isteyip istemediðini kontrol etmeliyiz
	    free(temp);
	    previousNode->next= NULL;
	   }
	   else{
	    free(temp);
	    previousNode->next = nextNode;
     	nextNode->prev = previousNode;
     }
	printf("---Silindi!!!---\n"),
    system ("pause");
    system ("cls");
    }
 }
}

void printNode (void){//Bu fonksiyon listeyi ekrana yazdýrýr
	
	struct node * temp = start;//Listede olaþým için geçici iþaretçi
	system("cls");
	printf ("Liste:\n\n");
	while (temp !=NULL){//Yazdýrma döngüsü
		printf ("%d\n",temp->data);
		temp= temp->next;
	}
	printf("\n");
	system ("pause");
	system ("cls");
}

int main(void){
	
	int i,choice,data,sdata;
	//selection screen
	while (1){
		printf("[1] Basa Ekleme\n[2] Sona Ekleme\n[3] Araya Ekleme\n[4] Veri Silme\n[5] Listeyi Yazdir\n[6] Veri Ara\n");
		printf("\nLutfen Seciminizi Yapin: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				system ("cls");
				printf("Veri Giriniz: ");
				scanf("%d",&data);
				addToFirst(data);
				break;
			case 2:
				system ("cls");
				printf("Veri Giriniz: ");
				scanf("%d",&data);
				addToLast(data);
				break;
			case 3:
				system ("cls");
				printf("Oncesine ekleme yapmak istediginiz veriyi giriniz: ");
				scanf("%d",&sdata);
				printf("\n");
				printf("Veri Giriniz: ");
				scanf("%d",&data);
				insertion(sdata,data);
				break;
			case 4:
				system ("cls");
				printf ("Silinmesiniz istediginiz veriyi giriniz: ");
				scanf("%d",&sdata);
				deleteNode(sdata);
				break;
			case 5:
				printNode();
				break;
			case 6:
				system ("cls");
				printf("Aranacak Veriyi Giriniz: ");
				scanf("%d",&sdata);
				searchNode(sdata);
				break;
		}
	}
}
