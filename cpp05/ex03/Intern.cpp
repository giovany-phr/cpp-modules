
# include "./includes/Intern.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(AForm const &other)
{
    std::cout << "Intern constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator = (AForm const &other)
{
    std::cout << "Intern assignation constructor called" << std::endl;
    (void) other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

static AForm   *makePresidentialPardon(std::string targetForm)
{
    std::cout << "PresidentialPardon created" << std::endl;
    return (new PresidentialPardonForm(targetForm));
}

static AForm   *makeRobotomyRequest(std::string targetForm)
{
    std::cout << "RobotomyRequest Form created" << std::endl;
    return (new RobotomyRequestForm(targetForm));
}

static AForm   *makeShrubberyCreation(std::string targetForm)
{
    std::cout << "ShrubberyCreation Form created" << std::endl;
    return (new ShrubberyCreationForm(targetForm));
}

AForm   *Intern::makeForm(const std::string nameForm, const std::string targetForm)
{
    AForm *(*ftPtr[3])(std::string target);
    std::string tab[3];

    (void) nameForm;
    (void) targetForm;

    ftPtr[0] = &makeShrubberyCreation;
    ftPtr[1] = &makeRobotomyRequest;
    ftPtr[2] = &makePresidentialPardon;
    tab[0] = "ShrubberyCreation";
    tab[1] = "RobotomyRequest";
    tab[2] = "PresidentialPardon";


    for (int i = 0; i < 3; i++)
    {
        if (nameForm == tab[i])
            return (ftPtr[i](targetForm));
    }
    throw errorFormNotFound();
    return (NULL);
}

//////////////////////////////////////////////
////////-----------EXCEPTION----------////////
//////////////////////////////////////////////

const char *Intern::errorFormNotFound::what() const throw()
{
    return ("Error: Form not found\n");
}