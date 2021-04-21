#pragma once
#include <stdio.h>
#include <string.h>

namespace std {
	class dstring {
	char* content = new char[1];
	int length = 0;
	int free = 0;
		int _add(const char* buff_new) {
			if (dynamic)
			{
				length += sizeof(buff_new);
				/*if (length != 0) {
					delete[] content;
				}
				content = new char[length];*/
				//sprintf(content, "%s%s", buff_old, buff_new);
				strncat(content, buff_new, sizeof(buff_new) + 1);
				return 0;
			}
			else
			{
				if (free <= 0)
				{
					return 1; //�]��ʣ�N���g
				}
				if (sizeof(buff_new) > free) {
					return 1; //���g����
				}
				free -= sizeof(buff_new);
				length += sizeof(buff_new);
				/*if (length != 0)
				{
					delete[] content;
				}
				content = new char[length];*/
				//sprintf(content, "%s%s", buff_old, buff_new);
				strncat(content, buff_new, sizeof(buff_new) + 1);
				return 0;
			}
		}
		int _speace(int size) {
			if (dynamic)
			{
				return 1; //�ӑB�ַ���������Ҫ������g
			}
			else
			{
				free += size;
				return 0;
			}
		}
		int _write(const char* buffer) {
			if (dynamic)
			{
				if (length != 0)
				{
					delete[] content;
					length = 0;
				}
				content = new char[sizeof(buffer)];
				strcpy(content, buffer);
			}
			else
			{
				if (free < sizeof(buffer)) {
					return 1; //���g����
				}
				if (length != 0)
				{
					delete[] content;
					length = 0;
				}
				content = new char[sizeof(buffer)];
				free -= sizeof(buffer);
				strcpy(content, buffer);
			}
			return 0;
		}
		void _remove() {
			if (length != 0)
			{
				delete[] content;
			}
			length = 0;
			free = 0;
			dynamic = true;
		}
		dstring _substring(int beginning, int length) {
			register int i = beginning;
			register int j = 0;
			char* temp;
			temp = new char[length];
			while (j < length)
			{
				temp[j] = content[i];
				i++;
				j++;
			}
			dstring result;
			result._write(temp);
			delete[] temp;
			return result;
		}
		public:
			bool dynamic = true;
			int add(const char* buff_new) {
				return _add(buff_new);
			}
			int speace(int size) {
				return _speace(size);
			}
			int write(const char* buffer) {
				return _write(buffer);
			}
			void remove() {
				_remove();
			}
			dstring subString(int beginning, int length) {
				return _substring(beginning, length);
			}
			char* stringLocation() {
				return content;
			}
			int getLength() {
				return length;
			}
			int freeSpeace() {
				return free;
			}
	};
}
