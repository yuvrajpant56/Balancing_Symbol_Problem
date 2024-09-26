import java.util.Scanner;
import java.util.Stack;
import java.util.ArrayList;

public class BracketBalancer {

    public static String areBracketBalancedPascal(String expr) {
        Stack<String> stack = new Stack<>();
        ArrayList<String> tokens = new ArrayList<>();
        int i = 0;

        // Tokenize the input
        while (i < expr.length()) {
            if (i + 5 <= expr.length() && expr.substring(i, i + 5).equals("begin")) {
                tokens.add("begin");
                i += 5;
            } else if (i + 3 <= expr.length() && expr.substring(i, i + 3).equals("end")) {
                tokens.add("end");
                i += 3;
            } else {
                tokens.add(String.valueOf(expr.charAt(i)));
                i++;
            }
        }

        // Clean tokens to only include valid symbols
        ArrayList<String> cleanedTokens = new ArrayList<>();
        for (String token : tokens) {
            if (token.equals("begin") || token.equals("(") || token.equals("{") || token.equals("[")
                    || token.equals("end") || token.equals(")") || token.equals("]") || token.equals("}")) {
                cleanedTokens.add(token);
            }
        }

        System.out.println(cleanedTokens);
      
    

        // Check for balanced symbols
        for (String token : cleanedTokens) {
            if (token.equals("begin") || token.equals("(") || token.equals("{") || token.equals("[")) {
                stack.push(token);
            } else {
                if (stack.isEmpty()) {
                    return "Unbalanced";
                }

                String currentChar = stack.pop();

                if (currentChar.equals("(") && !token.equals(")")) return "Unbalanced";
                if (currentChar.equals("{") && !token.equals("}")) return "Unbalanced";
                if (currentChar.equals("[") && !token.equals("]")) return "Unbalanced";
                if (currentChar.equals("begin") && !token.equals("end")) return "Unbalanced";
            }
        }

        if (!stack.isEmpty()) {
            return "Unbalanced";
        }

        return "Balanced";
    }

    public static String areBracketBalancedCPlusPlus(String expr) {
        Stack<String> stack = new Stack<>();
        ArrayList<String> tokens = new ArrayList<>();
        int i = 0;

        // Tokenize the input
        while (i < expr.length()) {
            if (i + 2 <= expr.length() && expr.substring(i, i + 2).equals("/*")) {
                tokens.add("/*");
                i += 2;
            } else if (i + 2 <= expr.length() && expr.substring(i, i + 2).equals("*/")) {
                tokens.add("*/");
                i += 2;
            } else {
                tokens.add(String.valueOf(expr.charAt(i)));
                i++;
            }
        }

        // Clean tokens to only include valid symbols
        ArrayList<String> cleanedTokens = new ArrayList<>();
        for (String token : tokens) {
            if (token.equals("/*") || token.equals("(") || token.equals("{") || token.equals("[")
                    || token.equals("*/") || token.equals(")") || token.equals("]") || token.equals("}")) {
                cleanedTokens.add(token);
            }
        }

        System.out.println(cleanedTokens);

        // Check for balanced symbols
        for (String token : cleanedTokens) {
            if (token.equals("/*") || token.equals("(") || token.equals("{") || token.equals("[")) {
                stack.push(token);
            } else {
                if (stack.isEmpty()) {
                    return "Unbalanced";
                }

                String currentChar = stack.pop();

                if (currentChar.equals("(") && !token.equals(")")) return "Unbalanced";
                if (currentChar.equals("{") && !token.equals("}")) return "Unbalanced";
                if (currentChar.equals("[") && !token.equals("]")) return "Unbalanced";
                if (currentChar.equals("/*") && !token.equals("*/")) return "Unbalanced";
            }
        }

        if (!stack.isEmpty()) {
            return "Unbalanced";
        }

        return "Balanced";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("************** ENTER number {1} TO CHECK FOR BALANCING SYMBOLS IN THE PASCAL LANGUAGE **********");
        System.out.println("************** ENTER number {2} TO CHECK FOR BALANCING SYMBOLS IN THE C++ LANGUAGE **********");

        int PASCAL = 1;
        int CPLUSCPLUS = 2;

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        scanner.nextLine();  // Consume the newline left by nextInt()

        if (PASCAL == num) {
            System.out.print("Enter the balancing symbol for PASCAL Language: ");
            String expr = scanner.nextLine();
            System.out.println("The expression entered by the user is: " + expr);
            System.out.println(areBracketBalancedPascal(expr));
        } else if (CPLUSCPLUS == num) {
            System.out.print("Enter the balancing symbol for C++ Language: ");
            String expr = scanner.nextLine();
            System.out.println("The expression entered by the user is: " + expr);
            System.out.println(areBracketBalancedCPlusPlus(expr));
        } else {
            System.out.println("You Entered Invalid Number: Sorry");
        }

        scanner.close();
    }
}
