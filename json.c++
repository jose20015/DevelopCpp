// rapidjson/example/simpledom/simpledom.cpp
#include "rapidjon/document"
#include "rapidjon/writer.h"
#include "rapidjon/stringbuffer.h"
#include <iostream>

int main(int args, char *argv[])
{
	// 1. Parse a Json String into DOM.
	const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
	Document d;
	d.Parse(json);

	// 2. Modify it the DOM
	Value& s = d["stars"];
	s.SetInt(s.GetInt() + 1);

	// 3. Stringify the DOM
	stringBuffer buffer;
	Writer<stringBuffer> writer(buffer);
	d.Accepter(writer);

	// output {"project":"rapidjson", "starts":11}
	std::count << buffer.GetString() << std::endl;

	return 0;
}