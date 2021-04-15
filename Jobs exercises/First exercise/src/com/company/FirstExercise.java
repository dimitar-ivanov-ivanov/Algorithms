package com.company;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class FirstExercise {

    public static void main(String[] args) {
        solve();
    }

    private static void solve() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input first array: ");
        int firstArr[] = inputArray(scanner);

        System.out.print("Input second array: ");
        int secondArr[] = inputArray(scanner);

        int firstArrMax = Arrays.stream(firstArr).max().getAsInt();

        int firstBucket[] = new int[firstArrMax + 1];

        fillBucketArray(firstArr, firstBucket);

        List<Integer> result = generateSortedArr(secondArr, firstBucket);
        addNumbersNotPresentInSecondArray(result, firstArr, firstBucket);

        System.out.println("Final result: ");
        result.forEach(num -> System.out.print(num + " "));
    }

    private static void addNumbersNotPresentInSecondArray(List<Integer> result, int[] firstArr, int[] firstBucket) {

        for (int i = 0; i < firstBucket.length; i++) {
            int num = firstBucket[i];
            if (num > 0) {
                addRangeToList(result, i, firstBucket[i]);
                firstBucket[i] = 0;
            }
        }
    }

    private static List<Integer> generateSortedArr(int[] secondArr,
                                                   int[] firstBucket) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < secondArr.length; i++) {
            int num = secondArr[i];
            if (firstBucket[num] > 0) {
                addRangeToList(result, num, firstBucket[num]);
                firstBucket[num] = 0;
            }
        }

        return result;
    }

    private static void addRangeToList(List<Integer> result,
                                       int num,
                                       int count) {

        for (int i = 0; i < count; i++) {
            result.add(num);
        }
    }

    private static void fillBucketArray(int[] inputArr, int[] bucket) {
        for (int i = 0; i < inputArr.length; i++) {
            bucket[inputArr[i]]++;
        }
    }


    private static int[] inputArray(Scanner scanner) {
        return Arrays
                .stream(scanner.nextLine().split("[ ,]"))
                .mapToInt(e -> Integer.parseInt(e))
                .toArray();
    }
}
