#pragma once
class Queue {
protected:
	int n;
	int *a;
private:
	Queue(int* a,int n) {
		a = new int [n];
	}
	Queue() {
		a = NULL;
	};
	~Queue() {
		delete a;
	};
	void set() {

	};
	void get() {

	};
};