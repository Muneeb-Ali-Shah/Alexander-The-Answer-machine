# Alexander – The Answer Machine

## English Explanation

**Alexander – The Answer Machine** is a C program that simulates a "mind-reading" trick. It is a cleverly disguised magic trick where the *boss* (the person who knows the secret) can secretly feed an answer into the program before the audience even asks a question. The audience then watches the program appear to magically "answer" the question.

### How It Works

1. **Startup:** The program displays the prompt:
   ```
   Enter: "Alexander! please answer the following question"
   ```
   The boss (or anyone else) is supposed to type this exact sentence.

2. **The Secret Trick (Boss Mode):**
   - While typing the sentence, the boss secretly presses the **`/` (slash)** key wherever a character of the predefined string would appear.
   - Every time `/` is pressed, the screen shows the correct next character of the predefined string (so it looks normal to any observer), but behind the scenes the program switches into **boss mode** and starts recording the boss's *actual keystrokes* as the hidden answer.
   - The boss types the **answer** they want the program to give later (e.g., `Blue`).
   - When the boss presses `/` a second time, boss mode ends and the program resumes displaying the predefined string normally.
   - To a bystander watching the screen, everything looks like the boss is just typing the prompt normally.

3. **The Question Phase:**
   - After the full sentence is "typed" and Enter is pressed, the program asks:
     ```
     Enter your question here:
     ```
   - Now anyone from the audience can type any question (e.g., *"What is the color of my shirt?"*).

4. **The Big Reveal:**
   - The program pretends to "think" for 3 seconds, then prints:
     ```
     Answer: Blue
     ```
   - The answer is the one the boss secretly entered between the two slashes — it looks like the program magically knew!

5. **Non-Boss Attempt:**
   - If someone runs the program without using the slash trick, they will simply see:
     ```
     No, I will answer my boss only.
     ```

### Summary of Key Variables

| Variable | Purpose |
|---|---|
| `predefined` | The sentence shown on screen as a "mask" |
| `answer` | Stores the secret answer typed by the boss |
| `boss` | Flag: `1` if boss mode was used, `0` otherwise |
| `currentIndex` | Tracks position in the `predefined` string |
| `answerIndex` | Tracks position while recording the secret answer |

---

## اردو وضاحت (Urdu Explanation)

**Alexander – The Answer Machine** ایک C زبان میں لکھا گیا پروگرام ہے جو ایک جادوئی ٹرک کی طرح کام کرتا ہے۔ اس میں صرف وہ شخص جسے ٹرک معلوم ہو (جسے پروگرام میں **boss** کہا گیا ہے) اسے چلا سکتا ہے۔

### یہ پروگرام کیا کرتا ہے؟

1. **شروع میں** پروگرام کہتا ہے:
   ```
   Enter: "Alexander! please answer the following question"
   ```
   یعنی یہ جملہ ٹائپ کریں۔

2. **خفیہ ٹرک:**
   - Boss جب یہ جملہ ٹائپ کرتا ہے تو بیچ میں **`/` (سلیش)** دباتا ہے۔
   - جب بھی `/` دبتا ہے، اسکرین پر جملے کا اگلا حرف خود بخود ظاہر ہو جاتا ہے (تاکہ دیکھنے والے کو لگے کہ boss ٹھیک ٹائپ کر رہا ہے)، لیکن اصل میں پروگرام اس وقت **boss کے دبائے گئے بٹنوں کو خفیہ جواب کے طور پر محفوظ کرنا شروع کر دیتا ہے**۔
   - مثال کے طور پر boss چاہتا ہے کہ جواب **"Blue"** ہو، تو وہ پہلا `/` دبانے کے بعد `Blue` ٹائپ کرتا ہے، پھر دوسرا `/` دباتا ہے۔
   - یہ سب اسکرین پر بالکل عام نظر آتا ہے۔

3. **سوال کا مرحلہ:**
   - جملہ مکمل ہونے کے بعد پروگرام پوچھتا ہے:
     ```
     Enter your question here:
     ```
   - اب کوئی بھی تماشہ بین اپنا سوال ٹائپ کر سکتا ہے، جیسے: *"میری قمیض کا رنگ کیا ہے؟"*

4. **جواب:**
   - پروگرام 3 سیکنڈ "سوچنے" کا ڈھونگ رچاتا ہے، پھر لکھتا ہے:
     ```
     Answer: Blue
     ```
   - یہ وہی جواب ہے جو boss نے خفیہ طور پر دو سلیشوں کے درمیان ٹائپ کیا تھا۔ دیکھنے والے کو لگتا ہے کہ پروگرام واقعی جادو جانتا ہے!

5. **عام شخص کی کوشش:**
   - اگر کوئی عام شخص بغیر ٹرک کے پروگرام چلائے تو صرف یہ لکھا آتا ہے:
     ```
     No, I will answer my boss only.
     ```

### خلاصہ

یہ پروگرام دراصل ایک **پارٹی ٹرک** ہے۔ Boss پہلے سے جواب خفیہ طور پر ڈال دیتا ہے، پھر audience کو لگتا ہے کہ پروگرام نے سوال سن کر خود جواب دیا۔ یہ کوئی اصل AI یا mind-reader نہیں، بلکہ ایک چالاک C پروگرام ہے!

---

## Output Screenshots

**Output when boss runs the program:**

<img width="449" alt="Screenshot 2024-01-14 201643" src="https://github.com/Muneeb-Ali-Shah/Alexander-The-Answer-machine/assets/154548736/8a7fc8dc-5076-4447-8295-08670c8cb8dd">

**Output when ordinary person runs the program:**

<img width="440" alt="Screenshot 2024-01-14 201722" src="https://github.com/Muneeb-Ali-Shah/Alexander-The-Answer-machine/assets/154548736/010f35b9-2b80-4537-8bb9-1bee8709e4f8">




