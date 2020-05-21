#pragma once


#include <memory>
#include <string>
#include <functional>


namespace ezapp {

    class Screen;
    class Timer;
    class Keyboard;
        
    // EzApp est �crit � partir de SFML
    //
    // La classe Application est au coeur de la librairie EzApp.
    //
    // Il suffit d'en cr�er une instance et d'appeler simplement la fonction run.
    // La fonction run requiert deux fonctions lui pemettant de faire :
    //  1. les calculs � chaque pas (consid�rant les entr�es au clavier et le temps �coul�)
    //  2. l'affichage pour chaque pas (l'affichage � l'�cran)
    class Application
    {
    public:
        class Parameters;
        using UpdateModelFunction = bool(Keyboard const &, Timer const &);
        using UpdateViewFunction = void(Screen &);

        Application();
        Application(Parameters const & parameters);
        ~Application();

        Parameters const & parameters() const;

        void run(std::function<UpdateModelFunction> updateModel, std::function<UpdateViewFunction> updateView);
        
        template <typename Model, typename View>
        void run(Model & model, bool(Model::*updateModel)(Keyboard const &, Timer const &), View & view, void(View::*updateView)(Screen &));
        template <typename ModelView>
        void run(ModelView& modelView, bool(ModelView::* updateModel)(Keyboard const&, Timer const&), void(ModelView::* updateView)(Screen&));

    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
        void * w();

        friend class Screen;
    };


    // Param�tres d'une application EzApp
    class Application::Parameters
    {
    public:
        Parameters(size_t width = 800, size_t height = 600, std::string const& title = "EzApp", std::string const& iconFileName = "", std::list<std::string> const& fontToPreload = {});

        bool isValid() const;                                               //!< Retourne vrai si les param�tres sont valides (principalement si la taille est suffisante)

        void setTitle(std::string const & title);                           //!< D�termine le titre de la fen�tre
        void setIconFileName(std::string const & iconFileName);             //!< D�termine le nom du fichier � charger repr�sentant l'ic�ne
        void setWindowSize(size_t width, size_t height);                    //!< D�termine la taille de la fen�tre
        void setFontToPreload(std::list<std::string> const & fontToPreload);//!< D�termine la liste des fichiers de police de caract�res � charger
        
        std::string title() const;                                          //!< return le titre de la fen�tre
        std::string iconFileName() const;                                   //!< Retourne le nom du fichier repr�sentant l'ic�ne
        size_t width() const;                                               //!< Retourne la largeur de la fen�tre
        size_t height() const;                                              //!< Retourne la hauteur de la fen�tre
        std::list<std::string> const & fontToPreload() const;               //!< Retourne la liste des fichiers de police de caract�res

        static size_t const minSize();                                      //!< Retourne la taille la plus petite permise de la fen�tre

    private:
        std::string mTitle;
        std::string mIconFileName;
        size_t mWidth;
        size_t mHeight;
        std::list<std::string> mFontToPreload;

        static size_t const sMinSize;
    };





    template <typename Model, typename View>
    inline void Application::run(Model & model, bool(Model::* updateModel)(Keyboard const &, Timer const &), View & view, void(View::* updateView)(Screen &)) {
        run(std::bind(updateModel, &model, std::placeholders::_1, std::placeholders::_2), std::bind(updateView, &view, std::placeholders::_1));
    }

    template <typename ModelView>
    inline void Application::run(ModelView& modelView, bool(ModelView::* updateModel)(Keyboard const&, Timer const&), void(ModelView::* updateView)(Screen&)) {
        run(modelView, updateModel, modelView, updateView);
    }
}
