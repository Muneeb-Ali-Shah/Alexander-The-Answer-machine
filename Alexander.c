/*
 * Alexander – The Answer Machine
 *
 * HOW THE TRICK WORKS:
 *   The program asks the user to type a fixed "predefined" sentence.
 *   If the user is the "boss" (knows the trick), they secretly press '/'
 *   at any point while typing.  The screen continues to display the
 *   predefined sentence normally, but everything the boss types between
 *   the first '/' and a second '/' is silently recorded as the answer.
 *   After the sentence is "typed" and Enter is pressed, the program asks
 *   for a question from the audience and then reveals the pre-entered
 *   answer — making it look like a mind-reader.
 *
 *   If no '/' is used, the program refuses to answer ("boss only").
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

int main() {
	/* ── Variables ─────────────────────────────────────────────────── */
	/* The sentence displayed on screen as a "mask" for the boss's input */
	char predefined[50] = {"Alexander! please answer the following question"};

	char answer[50];      /* Secretly recorded answer typed by the boss      */
	char currentChar;     /* Each character read from keyboard (no echo)     */
	int currentIndex = 0; /* Position in predefined[] being shown on screen  */
	int answerIndex  = 0; /* Position in answer[] being written              */
	int boss = 0;         /* 0 = normal user, 1 = boss mode was activated    */

	/* Tell the user which sentence to type */
	printf("Enter: \"%s\"\n", predefined);

	/* ── Phase 1: Read the "predefined" sentence ─────────────────────
	 * Keep reading characters until Enter (ASCII 13) is pressed.
	 * Normal characters are echoed directly.
	 * A '/' triggers the hidden boss-mode sequence (see below).
	 */
	while ((currentChar = getch()) != 13) {

		if (currentChar == 8) {
			/* Backspace (ASCII 8): erase the last visible character */
			putch('\b');
			putch(' ');
			putch('\b');
			currentIndex--;
			continue;
		}

		if (currentChar == 47) { /* '/' detected → enter boss mode */
			boss = 1;

			/* Show the next character of predefined[] on screen
			 * (so it looks like normal typing to any observer). */
			printf("%c", predefined[currentIndex++]);

			/* ── Boss-mode inner loop ────────────────────────────────
			 * While inside this loop the boss secretly types the answer.
			 * Each keystroke is stored in answer[] and the screen
			 * continues to display predefined[] characters, keeping
			 * the trick invisible to bystanders.
			 * A second '/' ends boss mode.
			 */
			while (1) {
				currentChar = getch();

				if (currentChar == 8) {
					/* Backspace inside boss mode */
					putch('\b');
					putch(' ');
					putch('\b');
					currentIndex--;
					continue;
				}

				if (currentChar == 47) {
					/* Second '/' → boss mode ends.
					 * Show one more predefined char, then read the
					 * very next key so typing can resume normally. */
					printf("%c", predefined[currentIndex]);
					currentChar = getch();
					break;
				}

				/* Regular key: record it as part of the answer and
				 * display the corresponding predefined character. */
				answer[answerIndex++] = currentChar;
				printf("%c", predefined[currentIndex++]);
			}
		}

		/* Echo the current character (or the char read after the
		 * closing '/' in boss mode) and advance the predefined index. */
		printf("%c", currentChar);
		currentIndex++;
	}

	/* ── Phase 2: Question & Answer ──────────────────────────────────*/
	if (boss == 1) {
		/* Boss used the trick: ask for a question, then reveal the answer */
		printf("\n\nEnter your question here:\n");
		scanf("%s");               /* Read (and discard) the audience question */
		printf("\nThinking...");
		sleep(3);                  /* Dramatic 3-second pause                  */
		printf("\n\nAnswer: %s", answer); /* Reveal the secretly stored answer */
	} else {
		/* No '/' was used → refuse to answer */
		printf("\n\nNo, I will answer my boss only.");
		printf("\n\n\t  ENDED");
	}

	return 0;
}
