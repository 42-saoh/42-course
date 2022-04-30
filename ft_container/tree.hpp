#ifndef TREE_HPP
# define TREE_HPP
# include "utils.hpp"
# include "iterator.hpp"
# include <memory>
# include <algorithm>

namespace ft
{
    enum _Rb_tree_color
    {
        _S_red = false,
        _S_black = true
    };

    struct _Rb_tree_node_base
    {
        typedef _Rb_tree_node_base* _Base_ptr;
        typedef const _Rb_tree_node_base* _Const_Base_ptr;

        _Rb_tree_color  _M_color;
        _Base_ptr  _M_parent;
        _Base_ptr  _M_left;
        _Base_ptr  _M_right;

        static _Base_ptr _S_minimum(_Base_ptr _x)
        {
            while (_x->_M_left != 0)
                _x = _x->_M_left;
            return (_x);
        }
  
        static _Const_Base_ptr _S_minimum(_Const_Base_ptr _x)
        {
            while (_x->_M_left != 0)
                _x = _x->_M_left;
            return (_x);
        }

        static _Base_ptr _S_maximum(_Base_ptr _x)
        {
            while (_x->_M_right != 0)
                _x = _x->_M_right;
            return (_x);
        }

        static _Const_Base_ptr _S_maximum(_Const_Base_ptr _x)
        {
            while (_x->_M_right != 0)
                _x = _x->_M_right;
            return (_x);
        }
    };

    template<typename _Tp>
    struct _Rb_tree_node : public _Rb_tree_node_base
    {
        typedef _Rb_tree_node<_Tp>* _Link_type;
        _Tp _M_value_field;
    };

    static _Rb_tree_node_base *local_Rb_tree_increment(_Rb_tree_node_base *_x) throw ()
    {
        if (_x->_M_right != 0)
        {
            _x = _x->_M_right;
            while (_x->_M_left != 0)
                _x = _x->_M_left;
        }
        else
        {
            _Rb_tree_node_base *_y = _x->_M_parent;
            while (_x == _y->_M_right)
            {
                _x = _y;
                _y = _y->_M_parent;
            }
            if (_x->_M_right != _y)
                _x = _y;
        }
        return (_x);
    }

    static _Rb_tree_node_base *local_Rb_tree_decrement(_Rb_tree_node_base *_x) throw ()
    {
        if (_x->_M_color == _S_red && _x->_M_parent->_M_parent == _x)
            _x = _x->_M_right;
        else if (_x->_M_left != 0)
        {
            _Rb_tree_node_base *_y = _x->_M_left;
            while (_y->_M_right != 0)
                _y = _y->_M_right;
            _x = _y;
        }
        else
        {
            _Rb_tree_node_base *_y = _x->_M_parent;
            while (_x == _y->_M_left)
            {
                _x = _y;
                _y = _y->_M_parent;
            }
            _x = _y;
        }
        return (_x);
    }
  
    _Rb_tree_node_base* _Rb_tree_increment(_Rb_tree_node_base *_x) throw ()
    {
        return (local_Rb_tree_increment(_x));
    }

    const _Rb_tree_node_base* _Rb_tree_increment(const _Rb_tree_node_base *_x) throw ()
    {
        return (local_Rb_tree_increment(const_cast<_Rb_tree_node_base *>(_x)));
    }
    
    _Rb_tree_node_base* _Rb_tree_decrement(_Rb_tree_node_base *_x) throw ()
    {
        return (local_Rb_tree_decrement(_x));
    }

    const _Rb_tree_node_base* _Rb_tree_decrement(const _Rb_tree_node_base *_x) throw ()
    {
        return (local_Rb_tree_decrement(const_cast<_Rb_tree_node_base *>(_x)));
    }

    template<typename _Tp>
    struct _Rb_tree_iterator
    {
        typedef _Tp  value_type;
        typedef _Tp& reference;
        typedef _Tp* pointer;
        typedef ft::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef _Rb_tree_iterator<_Tp> _Rb_iter;
        typedef _Rb_tree_node_base::_Base_ptr _Base_ptr;
        typedef _Rb_tree_node<_Tp>* _Link_type;

        _Base_ptr _M_node;

        _Rb_tree_iterator() : _M_node() {}

        explicit _Rb_tree_iterator(_Link_type _x) : _M_node(_x) {}

        reference operator*() const
        {
            return (static_cast<_Link_type>(_M_node)->_M_value_field);
        }

        pointer operator->() const
        {
            return (&(static_cast<_Link_type>(_M_node)->_M_value_field));
        }

        _Rb_iter &operator++()
        {
            _M_node = _Rb_tree_increment(_M_node);
            return (*this);
        }

        _Rb_iter operator++(int)
        {
            _Rb_iter _tmp = *this;
            _M_node = _Rb_tree_increment(_M_node);
            return (_tmp);
        }

        _Rb_iter &operator--()
        {
            _M_node = _Rb_tree_decrement(_M_node);
            return (*this);
        }

        _Rb_iter operator--(int)
        {
            _Rb_iter _tmp = *this;
            _M_node = _Rb_tree_decrement(_M_node);
            return (_tmp);
        }

        bool operator==(const _Rb_iter &_x) const
        {
            return (_M_node == __x._M_node);
        }

        bool operator!=(const _Rb_iter & __x) const
        {
            return (_M_node != __x._M_node);
        }
    };

    template<typename _Tp>
    struct _Rb_tree_const_iterator
    {
        typedef _Tp   value_type;
        typedef const _Tp& reference;
        typedef const _Tp* pointer;
        typedef _Rb_tree_iterator<_Tp> iterator;
        typedef bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef _Rb_tree_const_iterator<_Tp> _Rb_const_iter;
        typedef _Rb_tree_node_base::_Const_Base_ptr _Base_ptr;
        typedef const _Rb_tree_node<_Tp>*  _Link_type;

        _Base_ptr _M_node;

        _Rb_tree_const_iterator() : _M_node() { }
        explicit _Rb_tree_const_iterator(_Link_type _x) : _M_node(_x) { }
        _Rb_tree_const_iterator(const iterator &_it) : _M_node(_it._M_node) { }

        iterator _M_const_cast() const
        {
            return (iterator(static_cast<typename iterator::_Link_type>(const_cast<typename iterator::_Base_ptr>(_M_node))));
        }

        reference operator*() const
        {
            return (static_cast<_Link_type>(_M_node)->_M_value_field);
        }

        pointer operator->() const
        {
            return (&(static_cast<_Link_type>(_M_node)->_M_value_field));
        }

        _Rb_const_iter &operator++()
        {
            _M_node = _Rb_tree_increment(_M_node);
            return (*this);
        }
        
        _Rb_const_iter operator++(int)
        {
            _Rb_const_iter _tmp = *this;
            _M_node = _Rb_tree_increment(_M_node);
            return (_tmp);
        }

        _Rb_const_iter &operator--()
        {
            _M_node = _Rb_tree_decrement(_M_node);
            return (*this);
        }

        _Rb_const_iter operator--(int)
        {
            _Rb_const_iter _tmp = *this;
            _M_node = _Rb_tree_decrement(_M_node);
            return (_tmp);
        }

        bool operator==(const _Rb_const_iter& __x) const
        {
            return (_M_node == __x._M_node);
        }

        bool operator!=(const _Rb_const_iter& __x) const
        { 
            return (_M_node != __x._M_node);
        }
    };

    template<typename _Tp>
    bool operator==(const _Rb_tree_iterator<_Tp> &_x, const _Rb_tree_const_iterator<_Tp> &_y)
    {
        return (_x._M_node == _y._M_node);
    }

    template<typename _Tp>
    bool operator!=(const _Rb_tree_iterator<_Tp> &_x, const _Rb_tree_const_iterator<_Tp> &_y)
    {
        return (_x._M_node != _y._M_node);
    }

    void _Rb_tree_rotate_left(_Rb_tree_node_base *const _x, _Rb_tree_node_base *&_root)
    {
        _Rb_tree_node_base *const _y = _x->_M_right;

        _x->_M_right = _y->_M_left;
        if (_y->_M_left !=0)
            _y->_M_left->_M_parent = _x;
        _y->_M_parent = _x->_M_parent;
        if (_x == _root)
            _root = _y;
        else if (_x == _x->_M_parent->_M_left)
            _x->_M_parent->_M_left = _y;
        else
            _x->_M_parent->_M_right = _y;
        _y->_M_left = _x;
        _x->_M_parent = _y;
    }

    void _Rb_tree_rotate_right(_Rb_tree_node_base *const _x, _Rb_tree_node_base *&_root)
    {
        _Rb_tree_node_base *const _y = _x->_M_left;

        _x->_M_left = _y->_M_right;
        if (_y->_M_right != 0)
            _y->_M_right->_M_parent = _x;
        _y->_M_parent = _x->_M_parent;
        if (_x == _root)
            _root = _y;
        else if (_x == _x->_M_parent->_M_right)
            _x->_M_parent->_M_right = _y;
        else
            _x->_M_parent->_M_left = _y;
        _y->_M_right = _x;
        _x->_M_parent = _y;
    }

    void _Rb_tree_insert_and_rebalance(const bool _insert_left, _Rb_tree_node_base *_x, \
                            _Rb_tree_node_base *_p, _Rb_tree_node_base &_header) throw ()
    {
        _Rb_tree_node_base *&_root = _header._M_parent;
        _x->_M_parent = _p;
        _x->_M_left = 0;
        _x->_M_right = 0;
        _x->_M_color = _S_red;
        
        if (_insert_left)
        {
            _p->_M_left = _x;
            if (_p == &_header)
            {
                _header._M_parent = _x;
                _header._M_right = _x;
            }
            else if (_p == _header._M_left)
            _header._M_left = _x;
        }
        else
        {
            _p->_M_right = _x;
            if (_p == _header._M_right)
            _header._M_right = _x;
        }
        while (_x != _root && _x->_M_parent->_M_color == _S_red)
        {
            _Rb_tree_node_base *const _xpp = _x->_M_parent->_M_parent;
            if (_x->_M_parent == _xpp->_M_left)
            {
                _Rb_tree_node_base* const _y = _xpp->_M_right;
                if (_y && _y->_M_color == _S_red)
                {
                    _x->_M_parent->_M_color = _S_black;
                    _y->_M_color = _S_black;
                    _xpp->_M_color = _S_red;
                    _x = _xpp;
                }
                else
                {
                    if (_x == _x->_M_parent->_M_right)
                    {
                        _x = _x->_M_parent;
                        _Rb_tree_rotate_left(_x, _root);
                    }
                    _x->_M_parent->_M_color = _S_black;
                    _xpp->_M_color = _S_red;
                    _Rb_tree_rotate_right(_xpp, _root);
                }
            }
            else
            {
                _Rb_tree_node_base *const _y = _xpp->_M_left;
                if (_y && _y->_M_color == _S_red)
                {
                    _x->_M_parent->_M_color = _S_black;
                    _y->_M_color = _S_black;
                    _xpp->_M_color = _S_red;
                    _x = _xpp;
                }
                else
                {
                    if (_x == _x->_M_parent->_M_left)
                    {
                        _x = _x->_M_parent;
                        _Rb_tree_rotate_right(_x, _root);
                    }
                    _x->_M_parent->_M_color = _S_black;
                    _xpp->_M_color = _S_red;
                    _Rb_tree_rotate_left(_xpp, _root);
                }
            }
        }
        _root->_M_color = _S_black;
    }

    _Rb_tree_node_base* _Rb_tree_rebalance_for_erase(_Rb_tree_node_base *const _z, _Rb_tree_node_base &_header) throw ()
    {
        _Rb_tree_node_base *&_root = _header._M_parent;
        _Rb_tree_node_base *&_leftmost = _header._M_left;
        _Rb_tree_node_base *&_rightmost = _header._M_right;
        _Rb_tree_node_base* _y = _z;
        _Rb_tree_node_base* _x = 0;
        _Rb_tree_node_base* _x_parent = 0;

        if (_y->_M_left == 0)
            _x = _y->_M_right;
        else
        {
            if (_y->_M_right == 0)
                _x = _y->_M_left;
            else
            {
                _y = _y->_M_right;
                while (_y->_M_left != 0)
                    _y = _y->_M_left;
                _x = _y->_M_right;
            }
        }
        if (_y != _z)
        {
            _z->_M_left->_M_parent = _y;
            _y->_M_left = _z->_M_left;
            if (_y != _z->_M_right)
            {
                _x_parent = _y->_M_parent;
                if (_x) _x->_M_parent = _y->_M_parent;
                _y->_M_parent->_M_left = _x;
                _y->_M_right = _z->_M_right;
                _z->_M_right->_M_parent = _y;
            }
            else
                _x_parent = _y;
            if (_root == _z)
                _root = _y;
            else if (_z->_M_parent->_M_left == _z)
                _z->_M_parent->_M_left = _y;
            else
                _z->_M_parent->_M_right = _y;
            _y->_M_parent = _z->_M_parent;
            std::swap(_y->_M_color, _z->_M_color);
            _y = _z;
        }
        else
        {
            _x_parent = _y->_M_parent;
            if (_x)
                _x->_M_parent = _y->_M_parent;
            if (_root == _z)
                _root = _x;
            else
            {
                if (_z->_M_parent->_M_left == _z)
                    _z->_M_parent->_M_left = _x;
                else
                    _z->_M_parent->_M_right = _x;
            }
            if (_leftmost == _z)
            {
                if (_z->_M_right == 0)
                    _leftmost = _z->_M_parent;
                else
                    _leftmost = _Rb_tree_node_base::_S_minimum(_x);
            }
            if (_rightmost == _z)
            {
                if (_z->_M_left == 0)
                    _rightmost = _z->_M_parent;
                else
                    _rightmost = _Rb_tree_node_base::_S_maximum(_x);
            }
        }
        if (_y->_M_color != _S_red)
        {
            while (_x != _root && (_x == 0 || _x->_M_color == _S_black))
            {
                if (_x == _x_parent->_M_left)
                {
                    _Rb_tree_node_base  *_w = _x_parent->_M_right;
                    if (_w->_M_color == _S_red)
                    {
                        _w->_M_color = _S_black;
                        _x_parent->_M_color = _S_red;
                        _Rb_tree_rotate_left(_x_parent, _root);
                        _w = _x_parent->_M_right;
                    }
                    if ((_w->_M_left == 0 ||
                        _w->_M_left->_M_color == _S_black) &&
                        (_w->_M_right == 0 ||
                        _w->_M_right->_M_color == _S_black))
                    {
                        _w->_M_color = _S_red;
                        _x = _x_parent;
                        _x_parent = _x_parent->_M_parent;
                    }
                    else
                    {
                        if (_w->_M_right == 0
                            || _w->_M_right->_M_color == _S_black)
                            {
                            _w->_M_left->_M_color = _S_black;
                            _w->_M_color = _S_red;
                            _Rb_tree_rotate_right(_w, _root);
                            _w = _x_parent->_M_right;
                            }
                        _w->_M_color = _x_parent->_M_color;
                        _x_parent->_M_color = _S_black;
                        if (_w->_M_right)
                            _w->_M_right->_M_color = _S_black;
                        _Rb_tree_rotate_left(_x_parent, _root);
                        break;
                    }
                }
                else
                {
                    _Rb_tree_node_base* _w = _x_parent->_M_left;
                    if (_w->_M_color == _S_red)
                    {
                        _w->_M_color = _S_black;
                        _x_parent->_M_color = _S_red;
                        _Rb_tree_rotate_right(_x_parent, _root);
                        _w = _x_parent->_M_left;
                    }
                    if ((_w->_M_right == 0 || _w->_M_right->_M_color == _S_black) && (_w->_M_left == 0 || _w->_M_left->_M_color == _S_black))
                    {
                        _w->_M_color = _S_red;
                        _x = _x_parent;
                        _x_parent = _x_parent->_M_parent;
                    }
                    else
                    {
                        if (_w->_M_left == 0 || _w->_M_left->_M_color == _S_black)
                        {
                            _w->_M_right->_M_color = _S_black;
                            _w->_M_color = _S_red;
                            _Rb_tree_rotate_left(_w, _root);
                            _w = _x_parent->_M_left;
                        }
                        _w->_M_color = _x_parent->_M_color;
                        _x_parent->_M_color = _S_black;
                        if (_w->_M_left)
                            _w->_M_left->_M_color = _S_black;
                        _Rb_tree_rotate_right(_x_parent, _root);
                        break;
                    }
                }
            }
            if (_x)
                _x->_M_color = _S_black;
        }
        return (_y);
    }
};

#endif