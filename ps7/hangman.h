#define WORDLIST_FILENAME "words.txt"

void dell(char ch[], int index);
int guessed_letters(char guessed_word[]);
void pr(char guessed_word[]);
void registr(char *ch);
int clone(char letters_guessed[], char ch);

/**
 * Function detects, whether player guessed the secret word								 * Функция обнаруживает, угадал ли игрок секретное слово
 * Based on the letters player used for guessing, this function detects,				 * На основе буквы, используемой для угадывания, эта функция обнаруживает,
 * if it is possible to construct (and guess) the secret word from this set.			 * если можно построить (и угадать) секретное слово из этого множества.
 * If it is possible, function returns 1. If not, returns 0.							 * Если это возможно, функция возвращает 1. Если нет, возвращается 0.
 * @param secret the secret word lowercase											     * @param секрет секретного слова в нижнем регистре
 * @param letters_guessed the lowercase letters player already used in his guessing  	 * @param letters_guessed прописные буквы, которые уже используются в его угадывании
 * @return 1, if word is guess; 0 otherwise.											 * @ returnurn 1, если слово угадывает; 0 в противном случае.
 */
int is_word_guessed(const char secret[], const char letters_guessed[]);


/**
 * Function returns string representing the guessed word										* Функция возвращает строку, представляющую угаданное слово
 * This string contains visible letters, which were guessed successfuly							* Эта строка содержит видимые буквы, которые были угаданы успешно
 * by player at their correct positions. If there are still some hidden							* игрок на своих правильных позициях. Если еще есть какие-то скрытые
 * letters, the character '_' will be used for their representation.							* буквы, символ '_' будет использоваться для их представления.
 * @param secret the secret word lowercase														* @param секрет секретного слова в нижнем регистре
 * @param letters_guessed the lowercase letters player already used in his guessing				* @param letters_guessed прописные буквы, которые уже используются в его угадывании
 * @param guessed_word the constructed string as result of this function (output parameter)		* @param guessed_word построенная строка в результате этой функции (выходной параметр)
 */
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]);


/**
 * Returns all letters, which were not used for guessing								* Возвращает все буквы, которые не использовались для угадывания
 * Function returns set of lowercase letters sorted in alphabetical order. This			* Функция возвращает набор строчных букв, отсортированных в алфавитном порядке. это
 * set will contain all letters from the alphabet, but it ommits those, which			* set будет содержать все буквы из алфавита, но он омдит те, которые
 * were already guessed.																* уже были догаданы.
 * @param letters_guessed the lowercase letters player already used in his guessing		* @param letters_guessed прописные буквы, которые уже используются в его угадывании
 * @param available_letters set of lowercase not yet used letters						* @param available_letters набор нижних строчек, еще не использованных букв
 */
void get_available_letters(const char letters_guessed[], char available_letters[]);


/**
 * Starts interactive hangman game				* Запуск интерактивной игры в палач
 *												*
 * @param secret the secret word lowercase		* @param секрет секретного слова в нижнем регистре
 */
void hangman(const char secret[]);


/*
 * Returns the random word																			* Возвращает случайное слово
 * Function opens the file with all the words and reads randomly one of them						* Функция открывает файл со всеми словами и читает случайным образом один из них
 * into the buffer pointed by secret. Word consists of lowercase letters.							* в буфер, указанный тайной. Слово состоит из строчных букв.
 * If there is some error with reading the file, 1 is returned.										* Если при чтении файла есть некоторая ошибка, возвращается 1.
 * Don't forget to initialize the random numbers in your main() function will srand() call!			* Не забудьте инициализировать случайные числа в вашей функции main (), вызовет srand ()!
 * Otherwise (everything is ok), 0 is returned.														* В противном случае (все в порядке) возвращается 0.
 * @param secret buffer, where random word will be read												* @param секретный буфер, где будет читаться случайное слово
 * @return status code * @ код состояния возврата
 */
int get_word(char secret[]);