

# include "./includes/converter.hpp"

bool	isDuplicata(std::string str)
{
	std::string cmp = "+-.ef";

	for (int i = 0; i < 5; i++)
	{
		if (str.find_first_of(cmp[i]) != str.find_last_of(cmp[i]))
			return (true);
	}
	return (false);
}

bool	checkSigns(std::string str)
{
	if (str.find_first_of('-') != std::string::npos
		&& str.find_first_of('+') != std::string::npos)
		return (true);
	else if (str.find_first_of('+') != std::string::npos && *(str.begin()) != '+')
		return (true);
	else if (str.find_first_of('-') != std::string::npos && *(str.begin()) != '-')
		return (true);
	return (false);
}

bool	checkInput(std::string str)
{
	if (str.length() == 0 || isDuplicata(str) || checkSigns(str))
		return (false);
	else if (str.length() != 1 && (*(str.begin()) == '.' || *(str.end() - 1) == '.'))
		return (false);
	else if (str.find_first_of('f') != std::string::npos && *(str.end() - 1) != 'f')
		return (false);
	else if (str.length() != 1 && str.find_first_of('.') != std::string::npos)
	{
		size_t index = str.find_first_of('.');
		if (!isdigit(str[index + 1]))
			return (false);
	}
	return(true);
}

int	ft_isDigit(std::string str)
{
	if (str.find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (str.find_first_not_of("+-.0123456789") == std::string::npos)
		return (DOUBLE);
	else if (str.find_first_not_of("+-.0123456789f") == std::string::npos)
		return (FLOAT);
	return (ERR);
}

int	ft_isChar(std::string str)
{
	if (str.length() != 1)
		return (ERR);
	if (str[0] == '.' || str[0] == 'f' || str[0] == 'e'
		|| str[0] == '-' || str[0] == '+')
		return (CHAR);
	else if (std::isprint(str[0]) && !std::isdigit(str[0]))
		return (CHAR);
	return (ERR);
}

int ft_isSpe(std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf"
		|| str == "+inff" || str == "-inff")
		return (NAN_INF);
	return (0);
}

int	typeFinder(std::string str)
{
	int _type = -1;
	
	if (ft_isSpe(str) == NAN_INF)
		return (NAN_INF);
	if (checkInput(str) == false)
		return (ERR);
	else if (ft_isChar(str) == CHAR)
		return (CHAR);
	else
		_type = ft_isDigit(str);
	return (_type);
}