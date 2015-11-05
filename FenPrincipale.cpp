#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    creerActions();
    creerMenus();
    creerBarresOutils();
    creerBarreEtat();

    onglets = new QTabWidget;
    onglets->addTab(creerOngletPageWeb(tr("http://www.google.com")), tr("(Nouvelle page)"));
    connect(onglets, SIGNAL(currentChanged(int)), this, SLOT(changementOnglet(int)));
    setCentralWidget(onglets);

    setMinimumSize(500, 350);
    setWindowIcon(QIcon("images/phnavig.png"));
    setWindowTitle(tr("PhNavig"));
}

void FenPrincipale::creerActions()
{
    actionNouvelOnglet = new QAction(tr("&Nouvel onglet"), this);
    actionNouvelOnglet->setShortcut(tr("Ctrl+T"));
    connect(actionNouvelOnglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));
    actionFermerOnglet = new QAction(tr("&Fermer l'onglet"), this);
    actionFermerOnglet->setShortcut(tr("Ctrl+W"));
    connect(actionFermerOnglet, SIGNAL(triggered()), this, SLOT(fermerOnglet()));
    actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut(tr("Ctrl+Q"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    actionPrecedente = new QAction(QIcon("images/precedente.png"), tr("&Precedente"), this);
    actionPrecedente->setShortcut(QKeySequence::Back);
    connect(actionPrecedente, SIGNAL(triggered()), this, SLOT(precedente()));
    actionSuivante = new QAction(QIcon("images/suivante.png"), tr("&Suivante"), this);
    actionSuivante->setShortcut(QKeySequence::Forward);
    connect(actionSuivante, SIGNAL(triggered()), this, SLOT(suivante()));
    actionStop = new QAction(QIcon("images/stop.png"), tr("S&top"), this);
    connect(actionStop, SIGNAL(triggered()), this, SLOT(stop()));
    actionActualiser = new QAction(QIcon("images/actualiser.png"), tr("&Actualiser"), this);
    actionActualiser->setShortcut(QKeySequence::Refresh);
    connect(actionActualiser, SIGNAL(triggered()), this, SLOT(actualiser()));
    actionHome = new QAction(QIcon("images/home.png"), tr("A&ccueil"), this);
    connect(actionHome, SIGNAL(triggered()), this, SLOT(home()));
    actionGo = new QAction(QIcon("images/go.png"), tr("A&ller à"), this);
    connect(actionGo, SIGNAL(triggered()), this, SLOT(chargerPage()));

    actionAbout = new QAction(tr("&À propos..."), this);
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    actionAboutPhNavig = new QAction(tr("À propos du PhNavig..."), this);
    connect(actionAboutPhNavig, SIGNAL(triggered()), this, SLOT(aboutPhNavig()));
}

void FenPrincipale::creerMenus()
{
    QMenu *menuFichier = menuBar()->addMenu(tr("&Fichier"));

    menuFichier->addAction(actionNouvelOnglet);
    menuFichier->addAction(actionFermerOnglet);
    menuFichier->addSeparator();
    menuFichier->addAction(actionQuitter);

    QMenu *menuNavigation = menuBar()->addMenu(tr("Navigation"));

    menuNavigation->addAction(actionPrecedente);
    menuNavigation->addAction(actionSuivante);
    menuNavigation->addAction(actionStop);
    menuNavigation->addAction(actionActualiser);
    menuNavigation->addAction(actionHome);


    QMenu *menuAide = menuBar()->addMenu(tr("&?"));

    menuAide->addAction(actionAbout);
    menuAide->addAction(actionAboutPhNavig);
}

void FenPrincipale::creerBarresOutils()
{
    champAdresse = new QLineEdit;
    connect(champAdresse, SIGNAL(returnPressed()), this, SLOT(chargerPage()));

    QToolBar *toolBarNavigation = addToolBar(tr("Navigation"));

    toolBarNavigation->addAction(actionPrecedente);
    toolBarNavigation->addAction(actionSuivante);
    toolBarNavigation->addAction(actionStop);
    toolBarNavigation->addAction(actionActualiser);
    toolBarNavigation->addAction(actionHome);
    toolBarNavigation->addWidget(champAdresse);
    toolBarNavigation->addAction(actionGo);
}

void FenPrincipale::creerBarreEtat()
{
    progression = new QProgressBar(this);
    progression->setVisible(false);
    progression->setMaximumHeight(14);
    statusBar()->addWidget(progression, 1);
}



// Slots

void FenPrincipale::precedente()
{
    pageActuelle()->back();
}

void FenPrincipale::suivante()
{
    pageActuelle()->forward();
}

void FenPrincipale::home()
{
    pageActuelle()->load(QUrl(tr("http://www.google.com")));
}

void FenPrincipale::stop()
{
    pageActuelle()->stop();
}

void FenPrincipale::actualiser()
{
    pageActuelle()->reload();
}


void FenPrincipale::about()
{
    QMessageBox::information(this, tr("A propos..."), tr("PhNavig est un navigateur Internet libre et gratuit multiplate-forme codé en C++.<br /><strong>PhNavigo</strong> se veut rapide, sécurisé, simple et très facile d'utilisation.<br /><a href=\"http://blog.01tchat.com\">Site Web</a>."));
}

void FenPrincipale::aboutPhNavig()
{
    QMessageBox::information(this, tr("A propos de PhNavig"), tr("Ce navigateur à été créé par Pierre-Henry."));
}

void FenPrincipale::nouvelOnglet()
{
    int indexNouvelOnglet = onglets->addTab(creerOngletPageWeb(), tr("(Nouvelle page)"));
    onglets->setCurrentIndex(indexNouvelOnglet);

    champAdresse->setText("");
    champAdresse->setFocus(Qt::OtherFocusReason);
}

void FenPrincipale::fermerOnglet()
{
    if (onglets->count() > 1)
    {
        onglets->removeTab(onglets->currentIndex());
    }
    else
    {
        QMessageBox::critical(this, tr("Erreur"), tr("Il faut au moins un onglet !"));
    }
}

void FenPrincipale::chargerPage()
{
    QString url = champAdresse->text();

    // Add http:// if there is no one in the UR entered
    if (url.left(7) != "http://")
    {
        url = "http://" + url;
        champAdresse->setText(url);
    }

    pageActuelle()->load(QUrl(url));
}

void FenPrincipale::changementOnglet(int index)
{
    changementTitre(pageActuelle()->title());
    changementUrl(pageActuelle()->url());
}


void FenPrincipale::changementTitre(const QString & titreComplet)
{
    QString titreCourt = titreComplet;

    if (titreComplet.size() > 40)
    {
        titreCourt = titreComplet.left(40) + "...";
    }

    setWindowTitle(titreCourt + " - " + tr("PhNavig"));
    onglets->setTabText(onglets->currentIndex(), titreCourt);
}

void FenPrincipale::changementUrl(const QUrl & url)
{
    if (url.toString() != tr("html/page.html"))
    {
        champAdresse->setText(url.toString());
    }
}

void FenPrincipale::chargementDebut()
{
    progression->setVisible(true);
}

void FenPrincipale::chargementEnCours(int pourcentage)
{
    progression->setValue(pourcentage);
}

void FenPrincipale::chargementTermine(bool ok)
{
    progression->setVisible(false);
    statusBar()->showMessage(tr("Prêt"), 2000);
}



QWidget *FenPrincipale::creerOngletPageWeb(QString url)
{
    QWidget *pageOnglet = new QWidget;
    QWebView *pageWeb = new QWebView;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(pageWeb);
    pageOnglet->setLayout(layout);

    if (url.isEmpty())
    {
        pageWeb->load(QUrl(tr("html/page_blanche.html")));
    }
    else
    {
        if (url.left(7) != "http://")
        {
            url = "http://" + url;
        }
        pageWeb->load(QUrl(url));
    }

    connect(pageWeb, SIGNAL(titleChanged(QString)), this, SLOT(changementTitre(QString)));
    connect(pageWeb, SIGNAL(urlChanged(QUrl)), this, SLOT(changementUrl(QUrl)));
    connect(pageWeb, SIGNAL(loadStarted()), this, SLOT(chargementDebut()));
    connect(pageWeb, SIGNAL(loadProgress(int)), this, SLOT(chargementEnCours(int)));
    connect(pageWeb, SIGNAL(loadFinished(bool)), this, SLOT(chargementTermine(bool)));

    return pageOnglet;
}

QWebView *FenPrincipale::pageActuelle()
{
    return onglets->currentWidget()->findChild<QWebView *>();
}
