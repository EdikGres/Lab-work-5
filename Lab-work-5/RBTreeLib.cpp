#include <stdio.h>
#include <stdlib.h>
#include "RBTreeLib.h"

/*
-каждый узел ассоциируется с определенным цветом - красным или черным;
-корневой узел может быть любого цвета;
-красные узлы могут иметь только черные дочерние узлы;
-все пути от узла до любого листа, расположенного ниже в дереве, содержат одно и то же количество черных узлов.
height = от log(N+1) до 2 * log(N+1).
*/
namespace tree {
	int my_strcmp(const char* str1, const char* str2)
	{
		int s1;
		int s2;
		do {
			s1 = *str1++;
			s2 = *str2++;
			if (s1 == 0)
				break;
		} while (s1 == s2);
		return (s1 < s2) ? -1 : (s1 > s2);
	}
	int my_len_text(char* text) {
		int counter = 0;
		while (text[counter] != 0)
		{
			counter++;
		}
		return counter;
	}
	void rb_init(rb_tree* tree) {
		tree->count = 0;
		tree->root = NULL;

	}
	int is_red(rb_node* node)
	{
		return node != NULL && node->red == 1;
	}
	rb_node* rb_single(rb_node* root, int dir)
	{
		struct rb_node* save = root->link[!dir];

		root->link[!dir] = save->link[dir];
		save->link[dir] = root;

		root->red = 1;
		save->red = 0;

		return save;
	}

	/* функция для двукратного поворота узла */
	rb_node* rb_double(rb_node* root, int dir)
	{
		root->link[!dir] = rb_single(root->link[!dir], !dir);
		return rb_single(root, dir);
	}
	rb_node* make_node(char* data)
	{
		rb_node* rn = (rb_node*)malloc(sizeof * rn);

		if (rn != NULL) {
			rn->data = data;
			rn->red = 1; /* –инициализация красным цветом */
			rn->link[0] = NULL;
			rn->link[1] = NULL;
		}
		return rn;
	}
	int rb_insert(rb_tree* tree, char* data)
	{
		/* если добавляемый элемент оказывается первым */
		if (tree->root == NULL) {
			tree->root = make_node(data);
			if (tree->root == NULL)
				return 0;
		}
		else {
			rb_node head = { NULL }; /* временный корень дерева*/
			rb_node* g, * t;     /* дедушка и родитель */
			rb_node* p, * q;     /* родитель и итератор */
			int dir = 0, last;

			/* вспомогательные переменные */
			t = &head;
			g = p = NULL;
			q = t->link[1] = tree->root;

			/* основной цикл прохода по дереву */
			for (; ; )
			{
				if (q == NULL) {
					/* вставка узла */
					p->link[dir] = q = make_node(data);
					tree->count++;
					if (q == NULL)
						return 0;
				}
				else if (is_red(q->link[0]) && is_red(q->link[1]))
				{
					/* смена цвета */
					q->red = 1;
					q->link[0]->red = 0;
					q->link[1]->red = 0;
				}
				/* совпадение 2-х красных цветов */
				if (is_red(q) && is_red(p))
				{
					int dir2 = t->link[1] == g;

					if (q == p->link[last])
						t->link[dir2] = rb_single(g, !last);
					else
						t->link[dir2] = rb_double(g, !last);
				}

				/* такой узел в дереве уже есть  - выход из функции*/

				if (my_strcmp(q->data, data) == 0) // q->data == data
				{
					break;
				}

				last = dir;
				dir = my_strcmp(q->data, data) < 0; // если < в алфавитном порядке.

				if (g != NULL)
					t = g;
				g = p, p = q;
				q = q->link[dir];
			}

			/* обновить указатель на корень дерева*/
			tree->root = head.link[1];
		}
		/* сделать корень дерева черным */
		tree->root->red = 0;

		return 1;
	}
	void rb_println(rb_node* tree) {
		if (tree->link[0]) rb_println(tree->link[0]);
		printf("%s ", tree->data);
		if (tree->link[1]) rb_println(tree->link[1]);
	}
	//указатель, ибо нефиг стэк забивать.
	void rb_println_less(rb_node* tree, int* n) {
		int len = my_len_text(tree->data);
		if (tree->link[0]) rb_println_less(tree->link[0],  n);
		if (len < *n) {
			printf("%s ", tree->data);
		}
		if (tree->link[1]) rb_println_less(tree->link[1],  n);
	}

}