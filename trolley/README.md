
# Το Πρόβλημα του Τρόλεϊ 🚎

Αυτό το πρόγραμμα σε C ζητά από τον χρήστη να εισάγει το κόστος δύο πιθανών κατευθύνσεων του τρόλεϊ (αριστερά και δεξιά) και προτείνει την κατεύθυνση με το μικρότερο κόστος.

## Λειτουργικότητα Προγράμματος

### Σκοπός
Ο κύριος σκοπός αυτού του προγράμματος είναι:
1. **Αποδοχή κόστους κατεύθυνσης από τον χρήστη** για δύο επιλογές κατεύθυνσης: αριστερά και δεξιά.
2. **Σύγκριση των τιμών κόστους** και υποβολή πρότασης για την επιλογή της κατεύθυνσης με το μικρότερο κόστος.
3. **Διαχείριση λαθών**: Το πρόγραμμα τερματίζεται ομαλά σε περίπτωση που ο χρήστης δεν εισάγει τιμή ή όταν αντιμετωπίσει μη έγκυρη είσοδο.


---

## Δομή Κώδικα και Εξήγηση

### Επικεφαλίδες Βιβλιοθηκών
```c
#include <stdio.h>
#include <stdlib.h>
```
- **`#include <stdio.h>`**: Χρησιμοποιείται για λειτουργίες εισόδου/εξόδου, όπως `printf` για εκτύπωση και `scanf` για ανάγνωση δεδομένων από τον χρήστη.
- **`#include <stdlib.h>`**: Αν και σε αυτή την υλοποίηση δεν είναι αυστηρά απαραίτητη, μπορεί να χρησιμοποιηθεί για πρόσθετες λειτουργίες εξόδου `exit()` σε περίπτωση σφαλμάτων ή άλλες επεκτάσεις.

### Δήλωση Μεταβλητών
```c
long long right, left;
```
- **`long long right, left;`**: Μεταβλητές τύπου `long long int` για την αποθήκευση μεγάλων τιμών κόστους. Ο τύπος `long long` είναι κατάλληλος για την υποστήριξη μεγαλύτερων τιμών που ενδέχεται να εισάγει ο χρήστης.

### Λογική και Ροή του Προγράμματος

#### Επαναληπτικός Βρόχος
Το πρόγραμμα λειτουργεί μέσα σε έναν άπειρο βρόχο (`while(1)`), επιτρέποντας την επαναλαμβανόμενη εισαγωγή από τον χρήστη και την επεξεργασία δεδομένων μέχρι να επιτευχθεί ο τερματισμός.
```c
while(1) { ... }
```

#### Αρχικό Αίτημα Κόστους και Έλεγχος Εισόδου
1. **Εισαγωγή κόστους για αριστερή κατεύθυνση**: Το πρόγραμμα ζητά το κόστος για την αριστερή κατεύθυνση. 
2. **Έλεγχος EOF και νέας γραμμής**:
   - **EOF**: Αν η είσοδος είναι `EOF`, το πρόγραμμα τερματίζεται με μήνυμα.
   - **Νέα γραμμή (`\n`)**: Ελέγχουμε αν ο χρήστης πάτησε `Enter` μετά την τιμή του κόστους. Αν δεν συμβεί, το πρόγραμμα εμφανίζει μήνυμα σφάλματος και τερματίζεται.

```c
if (scanf("%lld", &left) == EOF) {
    printf("Terminating.");
    return 0;
} else if (Lresult != 1) {
    printf("No left cost provided.\n");
    return 1;
}
```

#### Είσοδος Κόστους Δεξιάς Κατεύθυνσης και Έλεγχος
Εφόσον το κόστος αριστερής κατεύθυνσης είναι έγκυρο, ζητείται το κόστος για τη δεξιά κατεύθυνση, με την ίδια διαδικασία ελέγχου.
1. **Επιτυχής ανάγνωση τιμής και νέας γραμμής**: Αν το κόστος δεξιάς κατεύθυνσης είναι έγκυρο, συνεχίζουμε στη σύγκριση.
2. **Μήνυμα λάθους**: Αν δεν εισαχθεί έγκυρη τιμή για τη δεξιά κατεύθυνση, εμφανίζεται μήνυμα **"No right cost provided."** και το πρόγραμμα τερματίζεται με κωδικό εξόδου `1`, σηματοδοτώντας σφάλμα στην είσοδο.

```c
if (scanf("%lld", &right) != 1) { 
    printf("No right cost provided.\n");
    return 1;
}
```

#### Σύγκριση Τιμών και Πρόταση Κατεύθυνσης
Η σύγκριση των τιμών πραγματοποιείται ως εξής:
- Αν το **αριστερό κόστος** είναι μικρότερο ή ίσο με το **δεξιό**, το πρόγραμμα προτείνει **"Go left!"**.
- Διαφορετικά, προτείνει **"Go right!"**.
  
```c
if (left <= right) {
    printf("Go left!\n");
} else {
    printf("Go right!\n");
}
```

---

## Παράδειγμα Εκτέλεσης
```plaintext
Please enter the cost of going left: 10
Please enter the cost of going right: 20
Go left!
Please enter the cost of going left: 30
Please enter the cost of going right: 25
Go right!
```

---

## Σημειώσεις Σχεδιασμού και Επεκτασιμότητας

- **Χρήση `long long`**: Προσφέρει τη δυνατότητα αποθήκευσης μεγαλύτερων αριθμητικών τιμών, κάνοντας το πρόγραμμα ευέλικτο για μεγαλύτερα κόστη.
- **Δομή επαναληπτικού βρόχου**: Επιτρέπει την εισαγωγή κόστους επανειλημμένα, καθιστώντας το πρόγραμμα διαισθητικό στη χρήση.

Αυτή η προσέγγιση διασφαλίζει τη σταθερή λειτουργία του προγράμματος, ακόμα και όταν ο χρήστης δεν ακολουθεί ακριβώς τη διαδικασία εισαγωγής.

---

