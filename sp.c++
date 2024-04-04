#include <iostream>
#include <cstring>

struct ProductionRule
{
    char left[10];
    char right[10];
};

int main()
{
    char input[20], stack[50], temp[50], ch[2], *token1, *token2, *substring;
    int i, j, stack_length, substring_length, stack_top, rule_count = 0;
    struct ProductionRule rules[10];
    stack[0] = '\0';

    // User input for the number of production rules
    std::cout << "\nEnter the number of production rules: ";
    std::cin >> rule_count;

    // User input for each production rule in the form 'left->right'
    std::cout << "\nEnter the production rules (in the form 'left->right'):\n";
    for (i = 0; i < rule_count; i++)
    {
        std::cin >> temp;
        token1 = strtok(temp, "->");
        token2 = strtok(NULL, "->");
        strcpy(rules[i].left, token1);
        strcpy(rules[i].right, token2);
    }

    // User input for the input string
    std::cout << "\nEnter the input string: ";
    std::cin >> input;
    i = 0;
    while (1)
    {
        // If there are more characters in the input string, add the next character to the stack
        if (i < strlen(input))
        {
            ch[0] = input[i];
            ch[1] = '\0';
            i++;
            strcat(stack, ch);
            std::cout << stack << "\t";
            for (int k = i; k < strlen(input); k++)
            {
                std::cout << input[k];
            }
            std::cout << "\tShift " << ch << std::endl;
        }

        // Iterate through the production rules
        for (j = 0; j < rule_count; j++)
        {
            // Check if the right-hand side of the production rule matches a substring in the stack
            substring = strstr(stack, rules[j].right);
            if (substring != NULL)
            {
                // Replace the matched substring with the left-hand side of the production rule
                stack_length = strlen(stack);
                substring_length = strlen(substring);
                stack_top = stack_length - substring_length;
                stack[stack_top] = '\0';
                strcat(stack, rules[j].left);
                std::cout << stack << "\t";
                for (int k = i; k < strlen(input); k++)
                {
                    std::cout << input[k];
                }
                std::cout << "\tReduce " << rules[j].left << "->" << rules[j].right << std::endl;
                j = -1; // Restart the loop to ensure immediate reduction of the newly derived production rule
            }
        }

        // Check if the stack contains only the start symbol and if the entire input string has been processed
        if (strcmp(stack, rules[0].left) == 0 && i == strlen(input))
        {
            std::cout << "\nAccepted";
            break;
        }

        // Check if the entire input string has been processed but the stack doesn't match the start symbol
        if (i == strlen(input))
        {
            std::cout << "\nNot Accepted";
            break;
        }
    }

    return 0;
}

/*
Enter the number of production rules: 4

Enter the production rules (in the form 'left->right'):
E->E+E
E->E*E
E->(E)
E->i

Enter the input string: i*i+i
i	*i+i	Shift i
E	*i+i	Reduce E->i
E*	i+i	Shift *
E*i	+i	Shift i
E*E	+i	Reduce E->i
E	+i	Reduce E->E*E
E+	i	Shift +
E+i		Shift i
E+E		Reduce E->i
E		Reduce E->E+E

Accepted
*/

