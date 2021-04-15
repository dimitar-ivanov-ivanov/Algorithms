package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class SecondExercise {
    public static void main(String[] args) {
        solve();
    }

    private static void solve() {
        MyLinkedList list = new MyLinkedList();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input list numbers: ");
        int[] nums = Arrays
                .stream(scanner.nextLine().split("[, ]"))
                .mapToInt(Integer::parseInt)
                .toArray();

        for (int num : nums) {
            list.addItem(num);
        }

        System.out.print("Input index of elements to swap: ");
        int indexOfElementsToSwap = Integer.parseInt(scanner.nextLine());

        //solve
        swapElements(list, indexOfElementsToSwap);
        printList(list);
    }

    private static void printList(MyLinkedList list) {
        Node node = list.getHead();
        while (node != null) {
            System.out.print(node.getValue() + " ");
            node = node.getNext();
        }
    }

    private static void swapElements(MyLinkedList list, int indexOfElementsToSwap) {
        Node firstNode = list.getElementAtIndex(indexOfElementsToSwap);
        Node secondNode = list.getLastElementAtIndex(indexOfElementsToSwap);
        list.swapNodeValues(firstNode, secondNode);
    }
}

class MyLinkedList {

    private int size;
    private Node head;
    private Node tail;

    public MyLinkedList() {
        this.size = 0;
    }

    public Node getHead() {
        return head;
    }

    public Node addItem(int val) {
        if (size == 0) {
            head = new Node(val);
            size++;

            return head;
        }

        //find end
        Node node = head;
        while (node.getNext() != null) {
            node = node.getNext();
        }

        Node newNode = new Node(val);
        node.setNext(newNode);
        newNode.setPrev(node);

        tail = newNode;
        size++;

        return newNode;
    }

    public Node getElementAtIndex(int index) {
        Node node = head;

        if (index < 0) {
            return null;
        }

        while (node != null) {
            index--;
            if (index == 0) {
                break;
            }
            node = node.getNext();
        }

        if (index > 0) {
            return null;
        }

        return node;
    }

    public Node getLastElementAtIndex(int index) {
        Node node = tail;

        if (index < 0) {
            return null;
        }

        while (node != null) {
            index--;
            if (index == 0) {
                break;
            }
            node = node.getPrev();
        }

        if (index > 0) {
            return null;
        }

        return node;
    }

    public void swapNodeValues(Node firstNode, Node secondNode) {
        int temp = firstNode.getValue();
        firstNode.setValue(secondNode.getValue());
        secondNode.setValue(temp);
    }

}

class Node {
    private int value;
    private Node next;
    private Node prev;

    public Node(int value) {
        this.value = value;
    }

    public Node getPrev() {
        return prev;
    }

    public void setPrev(Node prev) {
        this.prev = prev;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
