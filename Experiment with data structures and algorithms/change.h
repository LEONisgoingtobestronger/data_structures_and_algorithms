////���������򲻱䣬������������仯��ͬʱȥ�����š�
//	//	ת�������ǣ�����һ��ջ����������������ջΪ�գ�
//	//	������ɨ����׺���ʽ��������������ֱ�������
//
//	/*���������������ջ���Ƚϣ�ջ�����������ȵ�ǰ�������������ջ�������˳�ջ��Ԫ�ز������
//		���������ţ���ջ�����������ţ���һֱ��ջ�����ֱ���˵�������ֹ��
//		��ջ��ɿ�ʱ������Ľ����Ϊ��׺���ʽ��*/
// 
////��׺���ʽת��׺���ʽ����
string change(const string getstring)
{
	stack <char> str_stack;
	int start, end;
	string tempstring;
	string ss = "+-*/%()";
	string want;
	for (int i = 0; i < getstring.length(); i = end)
	{
		start = i;
		end = getstring.find_first_of(ss, i);
		if (start == end)
		{
			tempstring = getstring.substr(start, 1);
			end = end + 1;
		}
		else
		{

			if (end == -1)
			{
				end = getstring.length();
			}
			tempstring = getstring.substr(start, end - start);
		}
		if (tempstring == "(")
		{
			char c = '(';
			str_stack.push(c);
		}
		else if (tempstring == ")")
		{
			while (str_stack.top() != '(')
			{
				want += str_stack.top();
				want += " ";
				str_stack.pop();
			}str_stack.pop();

		}
		else if ((tempstring == "*") || (tempstring == "/"))
		{
			while ((str_stack.empty() != true) && (str_stack.top() == '*' || str_stack.top() == '/'))
			{
				want += str_stack.top();
				want += " ";
				str_stack.pop();
			}
			char c = tempstring[0];
			str_stack.push(c);
		}
		else if ((tempstring == "+") || (tempstring == "-"))
		{
			while ((str_stack.empty() != true) && (str_stack.top() != '('))
			{
				want += str_stack.top();
				want += " ";
				str_stack.pop();
			}
			char c = tempstring[0];
			str_stack.push(c);
		}
		else
		{
			want += tempstring;
			want += " ";
		}
	}
	while (str_stack.empty() != true)
	{
		want += str_stack.top();
		want += " ";
		str_stack.pop();

	}
	return want;

}



