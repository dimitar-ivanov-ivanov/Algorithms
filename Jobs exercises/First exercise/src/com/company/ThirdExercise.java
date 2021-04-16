package com.company;

import java.util.*;

public class ThirdExercise {
    public static void main(String[] args) {
        solve();
    }

    private static void solve() {
        Scanner scanner = new Scanner(System.in);
        String[] words = scanner.nextLine().split("[, ]");
        String chars = scanner.nextLine();
        HashSet<Character> charSet = new HashSet<>();
        addCharsToSet(chars, charSet);

        int lengthGoodStrings = getLengthOfGoodWords(words, charSet);
        System.out.println(lengthGoodStrings);
    }

    private static int getLengthOfGoodWords(String[] words, HashSet<Character> charSet) {
        int lengthGoodStrings = 0;

        for (String word : words) {
            boolean isGood = true;
            for (int j = 0; j < word.length(); j++) {
                Character ch = word.charAt(j);
                if (!charSet.contains(ch)) {
                    isGood = false;
                    break;
                }
            }

            if (isGood) {
                lengthGoodStrings += word.length();
            }
        }

        return lengthGoodStrings;
    }

    private static void addCharsToSet(String chars, HashSet<Character> charSet) {
        for (int i = 0; i < chars.length(); i++) {
            charSet.add(chars.charAt(i));
        }
    }
}
