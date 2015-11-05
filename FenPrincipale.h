#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtGui>
#include <QtWebKit>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        FenPrincipale();

    private:
        void creerActions();
        void creerMenus();
        void creerBarresOutils();
        void creerBarreEtat();
        QWidget *creerOngletPageWeb(QString url = "");
        QWebView *pageActuelle();

    private slots:
        void precedente();
        void suivante();
        void home();
        void stop();
        void actualiser();

        void about();
        void aboutPhNavig();
        void nouvelOnglet();
        void fermerOnglet();
        void chargerPage();
        void changementOnglet(int index);

        void changementTitre(const QString & titreComplet);
        void changementUrl(const QUrl & url);
        void chargementDebut();
        void chargementEnCours(int pourcentage);
        void chargementTermine(bool ok);

    private:
        QTabWidget *onglets;

        QAction *actionNouvelOnglet;
        QAction *actionFermerOnglet;
        QAction *actionQuitter;
        QAction *actionAbout;
        QAction *actionAboutPhNavig;
        QAction *actionPrecedente;
        QAction *actionSuivante;
        QAction *actionStop;
        QAction *actionActualiser;
        QAction *actionHome;
        QAction *actionGo;

        QLineEdit *champAdresse;
        QProgressBar *progression;
};

#endif
