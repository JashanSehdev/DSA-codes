
import java.util.*;

class PriorityQueue<type extends Comparable<type>> {
    Object[] pq;
    int size;
    Comparator<type> comparator;

    PriorityQueue(int capacity) {
        this.pq = new Object[capacity];
        this.size = 0;
        this.comparator = null;
    }

    PriorityQueue(int capacity, Comparator<type> c) {
        this.pq = new Object[capacity];
        this.size = 0;
        this.comparator = c;
    }
    
    public int size() {
        return size;
    }
    private int parent(int i) {
        if (i == 0)
            return i;
        return (i - 1) / 2;
    }

    private int left(int i) {
        return (i * 2) + 1;
    }

    private int right(int i) {
        return (i * 2) + 2;
    }

    private void swap(int i, int j) {
        Object temp = this.pq[i];
        this.pq[i] = this.pq[j];
        this.pq[j] = temp;
    }

    @SuppressWarnings("unchecked")
    private boolean less(int i, int j) {
        if (this.comparator != null) {
            return comparator.compare((type)this.pq[i], (type)this.pq[j]) < 0;
        }
        return ((type)this.pq[i]).compareTo((type) this.pq[j]) < 0;
    }

    private void swim(int i) {
        while (i > 0 && less(parent(i),i)) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    public boolean isFull() {
        return this.size >= this.pq.length;
    }

    public boolean isEmpty() {
        return this.size <= 0;
    }

    public void insert(type ele) {
        if (isFull()) {
            System.out.println(" queue is full");
            return;
        }

        this.pq[size++] = (type) ele;
        swim(size-1);
    }

    @SuppressWarnings("unchecked")
    public type delMax(){
        if (isEmpty()){
            System.out.println("queue is Empty");
            return null;
        }
        Object ele = this.pq[0];
        swap(0, --size);
        sink(0);
        return (type)ele;
    }
    
    private void sink (int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && less(largest, l)) largest = l;
        if (r < size && less(largest, r)) largest = r;

        if (largest != i) {
            swap(i, largest);
            sink(largest);
        }
    }

    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(32);
    pq.insert(2);
    pq.insert(7);
    pq.insert(4);
    pq.insert(5);
    pq.insert(3);
    pq.insert(3);
    pq.insert(2);
    pq.insert(9);

    assert pq.delMax() == 9;
    
    pq.insert(8);

    assert pq.isEmpty() == false;
    assert pq.size() == 8;
    assert pq.delMax() == 8;
    assert pq.delMax() == 7;
    assert pq.delMax() == 5;
    assert pq.delMax() == 4;
    assert pq.delMax() == 3;
    assert pq.delMax() == 3;
    assert pq.delMax() == 2;
    assert pq.delMax() == 2;
    }

}