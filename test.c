#include <stdio.h>

int main() {
    int preise[] = {100, 150, 200}; // Preise in Cent
    int auswahl, eingeworfen, restbetrag;

    printf("Willkommen beim Getränkeautomaten!\n");

    do {
        // Getränkeauswahl anzeigen
        printf("Wählen Sie ein Getränk aus:\n");
        printf("1 - Getränk 1 (1.00 €)\n");
        printf("2 - Getränk 2 (1.50 €)\n");
        printf("3 - Getränk 3 (2.00 €)\n");

        // Auswahl eingeben
        printf("Ihre Auswahl (1-3): ");
        if (scanf("%d", &auswahl) != 1) {
            while (getchar() != '\n'); // Eingabepuffer leeren
            continue;
        }

        // Auswahl prüfen und ggf. Zahlung abwickeln
        if (auswahl >= 1 && auswahl <= 3) {
            restbetrag = preise[auswahl - 1];
            printf("Sie haben Getränk %d gewählt. Preis: %.2f €\n", auswahl, restbetrag / 100.0);

            // Zahlung abwickeln
            do {
                printf("Bitte werfen Sie Geld ein (noch %.2f € fällig): ", restbetrag / 100.0);
                if (scanf("%d", &eingeworfen) != 1 || eingeworfen <= 0) {
                    while (getchar() != '\n'); // Eingabepuffer leeren
                    printf("Ungültige Eingabe! Bitte geben Sie einen positiven Betrag ein.\n");
                    continue;
                }

                restbetrag -= eingeworfen;

                if (restbetrag > 0) {
                    printf("Noch %.2f € erforderlich.\n", restbetrag / 100.0);
                } else if (restbetrag < 0) {
                    printf("Danke! Ihr Wechselgeld: %.2f €\n", -restbetrag / 100.0);
                }

            } while (restbetrag > 0);

            printf("Ihr Getränk %d wird ausgegeben. Vielen Dank für Ihren Einkauf!\n", auswahl);
            break; // Programm beenden, wenn ein Getränk erfolgreich ausgegeben wurde

        } else {
            printf("Ungültige Auswahl! Bitte wählen Sie zwischen 1 und 3.\n");
        }

    } while (1);

    return 0;
}