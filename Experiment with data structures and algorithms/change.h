////���������򲻱䣬������������仯��ͬʱȥ�����š�
//	//	ת�������ǣ�����һ��ջ����������������ջΪ�գ�
//	//	������ɨ����׺���ʽ��������������ֱ�������
//
//	/*���������������ջ���Ƚϣ�ջ�����������ȵ�ǰ�������������ջ�������˳�ջ��Ԫ�ز������
//		���������ţ���ջ�����������ţ���һֱ��ջ�����ֱ���˵�������ֹ��
//		��ջ��ɿ�ʱ������Ľ����Ϊ��׺���ʽ��*/
// 
////��׺���ʽת��׺���ʽ����

//�����Ż����޷����㺬�и����ı��ʽ
string change(const string getstring)//��׺���ʽת��׺���ʽ
{
	stack <char> str_stack;//�������������ջ
	int start, end;//�����洦����ֶε�ʼĩ
	string tempstring;//�м��ַ���
	string ss = "+-*/%()";//����
	string want;
	for (int i = 0; i < getstring.length(); i = end)//ɨ��
	{
		start = i;
		end = getstring.find_first_of(ss, i);
		if (start == end)//�ַ�
		{
			tempstring = getstring.substr(start, 1);
			end = end + 1;
		
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
			else if (tempstring == "+")
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
			else if (tempstring == "-")//���ڼ����п��ܴ����� �ʽ�������ֿ�����
			{
				end = end - 1;
				if (end==0)
				{
					end = getstring.find_first_of(ss, 1);
					want += getstring.substr(start, end - start);
					want += " ";
				}
				else if (end >= 1)
				{
					string a1;
					int end1 = end;
					a1 = getstring.substr(end - 1, 1);
					if (a1 == "(")
					{
						end = getstring.find_first_of(ss, end + 1);
						want += getstring.substr(end1, end - end1);
						want += " ";
					}

					
				}
				else
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
			}
		
		}
		else//����
		{

			if (end == -1)
			{
				end = getstring.length();
			}
			tempstring = getstring.substr(start, end - start);

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



