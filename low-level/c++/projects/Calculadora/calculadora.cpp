double calcular(double n1, double n2, char op) {
	switch (op)	{
	case '+':
		return n1 + n2;
		break;
	case '-':
		return n1 - n2;
		break;
	case '*':
		return n1 * n2;
		break;
	case '/':
		return n1 / n2;
		break;
	default:
		throw false;
	}
}