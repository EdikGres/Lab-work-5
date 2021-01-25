#ifndef RBTREE_LIB
#define RBTREE_LIB

namespace tree {
	typedef struct rb_node
	{
		char red; // ���� ���� ����� ������� ���, �.�. ����� ��� �������� 1 � 0
		char* data; // �������� ����
		rb_node* link[2]; //
	};
	typedef struct rb_tree
	{
		rb_node* root; // ��������� �� �������� ����
		int count; // ���������� ����� � ������
	};
	void rb_init(rb_tree* tree);
	//int is_red(rb_node* node);
	//rb_node* rb_single(rb_node* root, int dir);
	//rb_node* rb_double(rb_node* root, int dir);
	//rb_node* make_node(char* data);
	int rb_insert(rb_tree* tree, char* data);
	void rb_println(rb_node* tree);
	void rb_println_less(rb_node* tree, int* n);
};


#endif