#include "BlogPost.h"

BlogPost::BlogPost(const std::string &authorName, const std::string &title, const std::string &text,
                   const std::string &publicationDate) : authorName(authorName), title(title), text(text),
                                                         publicationDate(publicationDate)
{}

const std::string &BlogPost::getAuthorName() const
{
    return authorName;
}

void BlogPost::setAuthorName(const std::string &authorName)
{
    BlogPost::authorName = authorName;
}

const std::string &BlogPost::getTitle() const
{
    return title;
}

void BlogPost::setTitle(const std::string &title)
{
    BlogPost::title = title;
}

const std::string &BlogPost::getText() const
{
    return text;
}

void BlogPost::setText(const std::string &text)
{
    BlogPost::text = text;
}

const std::string &BlogPost::getPublicationDate() const
{
    return publicationDate;
}

void BlogPost::setPublicationDate(const std::string &publicationDate)
{
    BlogPost::publicationDate = publicationDate;
}
