#pragma once


template <typename T> struct m_elem {
	T m_data;
	m_elem *next, *prev;
};

template <typename T> class Container {
private:
	m_elem<T>* head, * tail;
	unsigned int count;
public:
	
	Container() {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	Container(const Container& incontainer) {
		head = tail = NULL;
		
		m_elem<T>* temp = incontainer.head;
		while (temp != 0) {
			AddTail(temp->m_data);
			temp = temp->next;
		}
	}

	~Container() {
		DelAll();
	}
	void DelAll() {
		while (count != 0) {
			Del(1);
		}
	}
	void Del(unsigned int pos) {
		if (pos == 0) {
			std::cout << "meh pos==0" << std::endl;
		}
		if (pos <1 || pos >count) {
			std::cout << "meh pos <1 || pos >count" << std::endl;
			return;
		}
		auto i = 1;
		m_elem<T>* delpos = head;
		while (i < pos) {
			delpos = delpos->next;
			i++;
		}
		if (delpos->prev != NULL && count != 1) {
			(delpos->prev)->next = delpos->next;
		}
		if (delpos->next != NULL && count != 1) {
			delpos->next->prev = delpos->prev;
		}
		if (pos == 1) {
			head = delpos->next;
		}
		if (pos == count) {
			tail = delpos->prev;
		}
		delete delpos;
		count--;
	}
	m_elem<T>* GetElem(unsigned int pos) {
		m_elem<T>* temp = head;
		if (pos < 1 || pos > count)
		{
			std::cout << "Incorrect position !!!\n";
			return 0;
		}
		auto i = 1;
		while (i < pos && temp != 0) {
			temp = temp->next;
			i++;
			}
		if (temp == 0)
			return 0;
		else
			return temp;
	}
	T GetData(unsigned int pos) {
		return GetElem(pos)->m_data;
	}
	unsigned int GetLenght() {
		return count;
	}
	void Print()
	{
		// Если в списке присутствуют элементы, то пробегаем по нему
		// и печатаем элементы, начиная с головного
		std::cout << "( ";
		if (count != 0)
		{
			m_elem<T>* temp = head;
			
			while (temp->next != 0)
			{
				std::cout << temp->m_data << ", ";
				temp = temp->next;
			}
			std::cout << temp->m_data;
		}
		std::cout << " )\t";
	}
	void PrintRev()
	{
		// Если в списке присутствуют элементы, то пробегаем по нему
		// и печатаем элементы, начиная с головного
		std::cout << "( ";
		if (count != 0)
		{
			m_elem<T>* temp = tail;

			while (temp->prev != 0)
			{
				std::cout << temp->m_data << ", ";
				temp = temp->prev;
			}
			std::cout << temp->m_data;
		}
		std::cout << " )\t";
	}
	void Print(unsigned int pos)
	{
		// Позиция от 1 до Count?
		if (pos < 1 || pos > count)
		{
			// Неверная позиция
			std::cout << "Incorrect position !!!\n";
			return;
		}

		m_elem<T>* temp;

		// Определяем с какой стороны 
		// быстрее двигаться
		if (pos <= count / 2)
		{
			// Отсчет с головы
			temp = head;
			auto i = 1;

			while (i < pos)
			{
				// Двигаемся до нужного элемента
				temp = temp->next;
				i++;
			}
		}
		else
		{
			// Отсчет с хвоста
			temp = tail;
			auto i = 1;

			while (i <= count - pos)
			{
				// Двигаемся до нужного элемента
				temp = temp->prev;
				i++;
			}
		}
		// Вывод элемента
		std::cout << pos << " element: ";
		std::cout << temp->m_data << std::endl;
	}

	void AddHead(int indata) {
		m_elem<T>* temp = new m_elem<T>;
		temp->m_data = indata;
		temp->prev = NULL;
		temp->next = head;
		if (head != NULL) {
			head->prev = temp;
		}
		if (count == 0) {
			head = temp;
			tail = temp;
		}
		else {
			head = temp;
		}
		count++;
	}
	void AddTail(int indata) {
		m_elem<T>* temp = new m_elem<T>;
		temp->m_data = indata;
		temp->next = NULL;
		temp->prev = tail;
		if (tail != 0) {
			tail->next = temp;
		}
		if (count == 0) {
			head = temp;
			tail = temp;
		}
		else {
			tail = temp;
		}
		count++;
	}
	Container& operator = (const Container& inContainer)
	{
		// Проверка присваивания элемента "самому себе"
		if (this == &inContainer)
			return *this;

		// удаление старого списка
		this->~Container(); // DelAll();

		m_elem<T>* temp = inContainer.head;

		// Копируем элементы
		while (temp != 0)
		{
			AddTail(temp->m_data);
			temp = temp->next;
		}

		return *this;
	}
	void Swap(unsigned int pos1, unsigned int pos2) {
		if (pos1<1 || pos2<1 || pos1>count || pos2>count) {
			std::cout << "swapping Incorrect position !!!\n";
			exit(1123);
		}
		if (pos1 != pos2) {

			m_elem<T>* pos1Elem = this->GetElem(pos1);
			m_elem<T>* pos2Elem = this->GetElem(pos2);
			m_elem<T>* prev1 = pos1Elem->prev;
			m_elem<T>* prev2 = pos2Elem->prev;
			m_elem<T>* next1 = pos1Elem->next;
			m_elem<T>* next2 = pos2Elem->next;

			if (pos2Elem == next1) {//обмен соседей1
				pos2Elem->next = pos1Elem;
				pos2Elem->prev = prev1;
				pos1Elem->next = next2;
				pos1Elem->prev = pos2Elem;
				if (next2 != NULL) {
					next2->prev = pos1Elem;
				}
				else {
					tail = pos1Elem;
				}
				if (pos1Elem != head) {
					prev1->next = pos2Elem;
				}
				else {
					head = pos2Elem;
				}
			}
			else {
				if (pos1Elem == next2) { //обмен соседей2
					pos1Elem->next = pos2Elem;
					pos1Elem->prev = prev2;
					pos2Elem->next = next1;
					pos2Elem->prev = pos1Elem;
					if (next1 != NULL) {
						next1->prev = pos2Elem;
					}
					else {
						tail = pos2Elem;
					}
					if (pos2Elem != head) {
						prev2->next = pos1Elem;
					}
					else {
						head = pos1Elem;
					}
				}
				else {//разностоящие эл-ты
					if (pos1Elem != head) {
						prev1->next = pos2Elem;
					}
					pos2Elem->next = next1;
					if (pos2Elem != head) {
						prev2->next = pos1Elem;
					}
					pos1Elem->next = next2;
					pos1Elem->prev = prev2;
					pos2Elem->next = next1;
					pos2Elem->prev = prev1;
					if (next2 != NULL) {
						next2->prev = pos1Elem;
					}
					if (next1 != NULL) {
						next1->prev = pos2Elem;
					}

					if (pos1Elem == head) {
						head = pos2Elem;
					}
					else {
						if (pos2Elem == head) {
							head = pos1Elem;
						}
					}
					{
						if (pos1Elem == tail)
						{
							tail = pos2Elem;
						}
						else {
							if (pos2Elem == tail) {
								tail = pos1Elem;
							}
						}
					}
				}

			}
		}
	}
	Container& Reverse(const Container& inContainer)
	{
		// удаление старого списка
		this->~Container(); // DelAll();

		m_elem<T>* temp = inContainer.head;

		// Копируем элементы
		while (temp != 0)
		{
			AddHead(temp->m_data);
			temp = temp->next;
		}

		return *this;
	}
	Container& Reverse()
	{
		Container<T> tempContainer = *this;
		this->~Container(); // DelAll();

		m_elem<T>* temp = tempContainer.head;

		// Копируем элементы
		while (temp != 0)
		{
			AddHead(temp->m_data);
			temp = temp->next;
		}

		return *this;
	}
};