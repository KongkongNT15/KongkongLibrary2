namespace klib::Kongkong::Text
{

}

namespace std
{
	ostream& operator<<(ostream& out, ::klib::Kongkong::Text::CharStringView view)
	{
		return out.write(view.Data(), static_cast<streamsize>(view.Length()));
	}
}