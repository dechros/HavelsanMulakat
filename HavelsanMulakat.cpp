// HavelsanMulakat.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

vector<Node*>dizi;

bool detectLoop(Node * head);
void push(struct Node** head_ref, int new_data);

int main()
{
	struct Node* head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);
	head->next->next->next->next = head;
	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";
	return 0;
}

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */ struct Node *new_node = new Node;
	/* put in the data */ new_node->data = new_data;
	/* link the old list off the new node */ new_node->next = (*head_ref);
	/* move the head to point to the new node */ (*head_ref) = new_node;
}

bool detectLoop(Node * head)
{
	while (head->next != NULL)
	{
		dizi.push_back(head->next);

		for(int i = 0; i < dizi.size() - 1; i++)
		{
			if (dizi[i]->next == head->next)
			{
				return true;
			}
		}

		return false;
	}
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
