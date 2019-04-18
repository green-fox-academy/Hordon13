#include "Blog.h"
#include "BlogPost.h"

Blog::Blog(std::vector<BlogPost> allPost)
{
    _allPost = allPost;
}

void Blog::add(BlogPost newPost)
{
    _allPost.push_back(newPost);
}

void Blog::deletePost(int index)
{
    _allPost.erase(_allPost.begin() + index);
}

void Blog::update(int index, BlogPost updated)
{
    _allPost.at(index) = updated;
}

const std::vector<BlogPost> &Blog::getAllPost() const
{
    return _allPost;
}
