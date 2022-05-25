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

    _Rb_tree_node_base *local_Rb_tree_increment(_Rb_tree_node_base *_x) throw ()
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

    _Rb_tree_node_base *local_Rb_tree_decrement(_Rb_tree_node_base *_x) throw ()
    {
        if (_x->_M_color == _S_red && _x->_M_parent->_M_parent == _x)
            _x = _x->_M_right;
        else if (_x->_M_left != 0)
        {
            _x = _x->_M_left;
            while (_x->_M_right != 0)
                _x = _x->_M_right;
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
        typedef std::bidirectional_iterator_tag iterator_category;
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
            return (_M_node == _x._M_node);
        }

        bool operator!=(const _Rb_iter & _x) const
        {
            return (_M_node != _x._M_node);
        }
    };

    template <typename _Tp>
    struct _Rb_tree_const_iterator
    {
        typedef _Tp   value_type;
        typedef const _Tp& reference;
        typedef const _Tp* pointer;
        typedef _Rb_tree_iterator<_Tp> iterator;
        typedef std::bidirectional_iterator_tag iterator_category;
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

    void _Rb_tree_refectoring_right(_Rb_tree_node_base *&_x, _Rb_tree_node_base *const _xpp, _Rb_tree_node_base *&_root)
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

    void _Rb_tree_refectoring_left(_Rb_tree_node_base *&_x, _Rb_tree_node_base *const _xpp, _Rb_tree_node_base *&_root)
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

    void _Rb_tree_recoloring(_Rb_tree_node_base *&_x, _Rb_tree_node_base *const _y, _Rb_tree_node_base *const _xpp)
    {
        _x->_M_parent->_M_color = _S_black;
        _y->_M_color = _S_black;
        _xpp->_M_color = _S_red;
        _x = _xpp;
    }

    void _Rb_tree_insert_and_rebalance(const bool _insert_left, _Rb_tree_node_base *_x, _Rb_tree_node_base *_p, _Rb_tree_node_base &_header)
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
                _Rb_tree_node_base *const _y = _xpp->_M_right;
                if (_y && _y->_M_color == _S_red)
                    _Rb_tree_recoloring(_x, _y, _xpp);
                else
                    _Rb_tree_refectoring_left(_x, _xpp, _root);
            }
            else
            {
                _Rb_tree_node_base *const _y = _xpp->_M_left;
                if (_y && _y->_M_color == _S_red)
                    _Rb_tree_recoloring(_x, _y, _xpp);
                else
                    _Rb_tree_refectoring_right(_x, _xpp, _root);
            }
        }
        _root->_M_color = _S_black;
    }

    _Rb_tree_node_base *_Rb_tree_rebalance_for_erase(_Rb_tree_node_base *const _z, _Rb_tree_node_base &_header)
    {
        _Rb_tree_node_base *&_root = _header._M_parent;
        _Rb_tree_node_base *&_leftmost = _header._M_left;
        _Rb_tree_node_base *&_rightmost = _header._M_right;
        _Rb_tree_node_base *_y = 0;
        _Rb_tree_node_base *_x = 0;
        _Rb_tree_node_base *_x_parent = 0;

        if (_z->_M_left == 0)
            _x = _z->_M_right;
        else
        {
            if (_z->_M_right == 0)
                _x = _z->_M_left;
            else
            {
                _y = _z->_M_right;
                while (_y->_M_left != 0)
                    _y = _y->_M_left;
                _x = _y->_M_right;
            }
        }
        if (_y)
        {
            _z->_M_left->_M_parent = _y;
            _y->_M_left = _z->_M_left;
            if (_y != _z->_M_right)
            {
                _x_parent = _y->_M_parent;
                if (_x)
                    _x->_M_parent = _y->_M_parent;
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
        }
        else
        {
            _x_parent = _z->_M_parent;
            if (_x)
                _x->_M_parent = _z->_M_parent;
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
        if (_z->_M_color != _S_red)
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
                    if ((_w->_M_left == 0 || _w->_M_left->_M_color == _S_black)
                        && (_w->_M_right == 0 || _w->_M_right->_M_color == _S_black))
                    {
                        _w->_M_color = _S_red;
                        _x = _x_parent;
                        _x_parent = _x_parent->_M_parent;
                    }
                    else
                    {
                        if (_w->_M_right == 0 || _w->_M_right->_M_color == _S_black)
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
                    if ((_w->_M_right == 0 || _w->_M_right->_M_color == _S_black)
                        && (_w->_M_left == 0 || _w->_M_left->_M_color == _S_black))
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
        return (_z);
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc = std::allocator<_Val> >
    class _Rb_tree
    {
        private:
            typedef typename _Alloc::template rebind<_Rb_tree_node<_Val> >::other _Node_alloc_type;

        protected:
            typedef _Rb_tree_node_base* _Base_ptr;
            typedef const _Rb_tree_node_base* _Const_Base_ptr;

        public:
            typedef _Key key_type;
            typedef _Val value_type;
            typedef _Alloc allocator_type;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef _Rb_tree_node<_Val>* _Link_type;
            typedef const _Rb_tree_node<_Val>* _Const_Link_type;
            typedef typename allocator_type::size_type size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef _Rb_tree_iterator<value_type> iterator;
            typedef _Rb_tree_const_iterator<value_type> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        protected:
            _Node_alloc_type& _M_get_Node_allocator()
            {
                return (*static_cast<_Node_alloc_type*>(&this->_M_base));
            }

            const _Node_alloc_type& _M_get_Node_allocator() const
            {
                return (*static_cast<const _Node_alloc_type*>(&this->_M_base));
            }

        public:
            allocator_type get_allocator() const
            {
                return (allocator_type(_M_get_Node_allocator()));
            }

        protected:
            _Link_type _M_allocate()
            {
                return (_M_base.allocate(1));
            }

            void _M_deallocate(_Link_type _p)
            {
                _M_base.deallocate(_p, 1);
            }

            _Link_type _M_create_node(const value_type& _x)
            {
                _Link_type _tmp = _M_allocate();

                try
                {
                    get_allocator().construct(&_tmp->_M_value_field, _x);
                }
                catch(...)
                {
                    _M_deallocate(_tmp);
                    std::runtime_error("memory alloc error");
                }
                return (_tmp);
            }

            void _M_destroy_node(_Link_type _p)
            {
                get_allocator().destroy(&(_p->_M_value_field));
                _M_deallocate(_p);
            }

            _Link_type _M_clone_node(_Const_Link_type _x)
            {
                _Link_type _tmp = _M_create_node(_x->_M_value_field);

                _tmp->_M_color = _x->_M_color;
                _tmp->_M_parent = 0;
                _tmp->_M_left = 0;
                _tmp->_M_right = 0;
                return (_tmp);
            }

            template <typename _Key_compare>
            struct _Rb_tree_base : public _Node_alloc_type
            {
                _Key_compare _M_key_compare;
                _Rb_tree_node_base _M_header;
                size_type _M_node_count;

                _Rb_tree_base() : _Node_alloc_type(), _M_key_compare(), _M_header(), _M_node_count(0)
                {
                    _M_initialize();
                }

                _Rb_tree_base(const _Key_compare& __comp, const _Node_alloc_type& __a)
                    : _Node_alloc_type(__a), _M_key_compare(__comp), _M_header(), _M_node_count(0)
                {
                    _M_initialize();
                }

                private:
                    void _M_initialize()
                    {
                        this->_M_header._M_color = _S_red;
                        this->_M_header._M_parent = 0;
                        this->_M_header._M_left = &this->_M_header;
                        this->_M_header._M_right = &this->_M_header;
                    }     
            };

            _Rb_tree_base<_Compare> _M_base;

            _Base_ptr &_M_root()
            {
                return (this->_M_base._M_header._M_parent);
            }

            _Const_Base_ptr _M_root() const
            {
                return (this->_M_base._M_header._M_parent);
            }

            _Base_ptr &_M_leftmost()
            {
                return (this->_M_base._M_header._M_left);
            }

            _Const_Base_ptr _M_leftmost() const
            {
                return (this->_M_base._M_header._M_left);
            }

            _Base_ptr &_M_rightmost()
            {
                return (this->_M_base._M_header._M_right);
            }

            _Const_Base_ptr _M_rightmost() const
            {
                return (this->_M_base._M_header._M_right);
            }

            _Link_type _M_begin()
            {
                return (static_cast<_Link_type>(this->_M_base._M_header._M_parent));
            }

            _Const_Link_type _M_begin() const
            {
                return (static_cast<_Const_Link_type>(this->_M_base._M_header._M_parent));
            }

            _Link_type _M_end()
            {
                return (static_cast<_Link_type>(&this->_M_base._M_header));
            }

            _Const_Link_type _M_end() const
            {
                return (static_cast<_Const_Link_type>(&this->_M_base._M_header));
            }

            static const_reference _S_value(_Const_Link_type _x)
            {
                return (_x->_M_value_field);
            }

            static const _Key &_S_key(_Const_Link_type _x)
            {
                return (_KeyOfValue()(_S_value(_x)));
            }

            static _Link_type _S_left(_Base_ptr _x)
            {
                return (static_cast<_Link_type>(_x->_M_left));
            }

            static _Const_Link_type _S_left(_Const_Base_ptr _x)
            {
                return (static_cast<_Const_Link_type>(_x->_M_left));
            }

            static _Link_type _S_right(_Base_ptr _x)
            {
                return (static_cast<_Link_type>(_x->_M_right));
            }

            static _Const_Link_type _S_right(_Const_Base_ptr _x)
            {
                return static_cast<_Const_Link_type>(_x->_M_right);
            }

            static const_reference _S_value(_Const_Base_ptr _x)
            {
                return (static_cast<_Const_Link_type>(_x)->_M_value_field);
            }

            static const _Key &_S_key(_Const_Base_ptr _x)
            {
                return (_KeyOfValue()(_S_value(_x)));
            }

            static _Base_ptr _S_minimum(_Base_ptr _x)
            {
                return (_Rb_tree_node_base::_S_minimum(_x));
            }

            static _Const_Base_ptr _S_minimum(_Const_Base_ptr _x)
            {
                return (_Rb_tree_node_base::_S_minimum(_x));
            }

            static _Base_ptr _S_maximum(_Base_ptr _x)
            {
                return (_Rb_tree_node_base::_S_maximum(_x));
            }

            static _Const_Base_ptr _S_maximum(_Const_Base_ptr _x)
            {
                return (_Rb_tree_node_base::_S_maximum(_x));
            }
            
        public:
            _Rb_tree() {}

            _Rb_tree(const _Compare &_comp, const allocator_type &_a = allocator_type())
                        : _M_base(_comp, _a) { }

            _Rb_tree(const _Rb_tree& _x) : _M_base(_x._M_base._M_key_compare, _x._M_get_Node_allocator())
            {
                if (_x._M_root() != 0)
                {
                    _M_root() = _M_copy(_x._M_begin(), _M_end());
                    _M_leftmost() = _S_minimum(_M_root());
                    _M_rightmost() = _S_maximum(_M_root());
                    _M_base._M_node_count = _x._M_base._M_node_count;
                }
            }
                
            ~_Rb_tree()
            {
                _M_erase(_M_begin());
            }

            _Rb_tree &operator=(const _Rb_tree& _x)
            {
                if (this != &_x)
                {
                    clear();
                    _M_base._M_key_compare = _x._M_base._M_key_compare;
                    if (_x._M_root() != 0)
                    {
                        _M_root() = _M_copy(_x._M_begin(), _M_end());
                        _M_leftmost() = _S_minimum(_M_root());
                        _M_rightmost() = _S_maximum(_M_root());
                        _M_base._M_node_count = _x._M_base._M_node_count;
                    }
                }
                return (*this);
            }

            _Compare key_comp() const
            {
                return (_M_base._M_key_compare);
            }

            iterator begin()
            { 
                return (iterator(static_cast<_Link_type>(this->_M_base._M_header._M_left)));
            }

            const_iterator begin() const
            { 
                return (const_iterator(static_cast<_Const_Link_type>(this->_M_base._M_header._M_left)));
            }

            iterator end()
            {
                return (iterator(static_cast<_Link_type>(&this->_M_base._M_header)));
            }

            const_iterator end() const
            { 
                return (const_iterator(static_cast<_Const_Link_type>(&this->_M_base._M_header)));
            }

            reverse_iterator rbegin()
            {
                return (reverse_iterator(end()));
            }

            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(end()));
            }

            reverse_iterator rend()
            {
                return (reverse_iterator(begin()));
            }

            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(begin()));
            }

            bool empty() const
            {
                return (_M_base._M_node_count == 0);
            }

            size_type size() const
            {
                return (_M_base._M_node_count);
            }

            size_type max_size() const
            {
                return (_M_get_Node_allocator().max_size());
            }

            void swap(_Rb_tree &_t)
            {
                if (_M_root() == 0)
                {
                    if (_t._M_root() != 0)
                    {
                        _M_root() = _t._M_root();
                        _M_leftmost() = _t._M_leftmost();
                        _M_rightmost() = _t._M_rightmost();
                        _M_root()->_M_parent = _M_end();

                        _t._M_root() = 0;
                        _t._M_leftmost() = _t._M_end();
                        _t._M_rightmost() = _t._M_end();
                    }
                }
                else if (_t._M_root() == 0)
                {
                    _t._M_root() = _M_root();
                    _t._M_leftmost() = _M_leftmost();
                    _t._M_rightmost() = _M_rightmost();
                    _t._M_root()->_M_parent = _t._M_end();

                    _M_root() = 0;
                    _M_leftmost() = _M_end();
                    _M_rightmost() = _M_end();
                }
                else
                {
                    std::swap(_M_root(), _t._M_root());
                    std::swap(_M_leftmost(), _t._M_leftmost());
                    std::swap(_M_rightmost(), _t._M_rightmost());

                    _M_root()->_M_parent = _M_end();
                    _t._M_root()->_M_parent = _t._M_end();
                }
                std::swap(this->_M_base._M_node_count, _t._M_base._M_node_count);
                std::swap(this->_M_base._M_key_compare, _t._M_base._M_key_compare);
            }

            void erase(iterator _pos)
            {
                _M_erase_single(_pos);
            }

            void erase(const_iterator _pos)
            {
                _M_erase_single(_pos);
            }

            size_type erase(const key_type &_x)
            {
                const size_type _old_size = size();

                _M_erase_range(lower_bound(_x), upper_bound(_x));
                return (_old_size - size());
            }

            void erase(iterator _first, iterator _last)
            {
                _M_erase_range(_first, _last);
            }

            void erase(const_iterator _first, const_iterator _last)
            {
                _M_erase_range(_first, _last);
            }

            void clear()
            {
                _M_erase(_M_begin());
                _M_leftmost() = _M_end();
                _M_root() = 0;
                _M_rightmost() = _M_end();
                _M_base._M_node_count = 0;
            }

            iterator find(const key_type &_k)
            {
                iterator _j = _M_lower_bound(_M_begin(), _M_end(), _k);

                if (_j == end() || _M_base._M_key_compare(_k, _S_key(_j._M_node)))
                    return (end());
                return (_j);
            }

            const_iterator find(const key_type &_k) const
            {
                const_iterator _j = _M_lower_bound(_M_begin(), _M_end(), _k);

                if (_j == end() || _M_base._M_key_compare(_k, _S_key(_j._M_node)))
                    return (end());
                return (_j);
            }

            size_type count(const key_type &_k) const
            {
                if (find(_k) != end())
                    return (1);
                return (0);
            }

            iterator lower_bound(const key_type &_k)
            {
                return (_M_lower_bound(_M_begin(), _M_end(), _k));
            }

            const_iterator lower_bound(const key_type &_k) const
            {
                return (_M_lower_bound(_M_begin(), _M_end(), _k));
            }

            iterator upper_bound(const key_type &_k)
            {
                return (_M_upper_bound(_M_begin(), _M_end(), _k));
            }

            const_iterator upper_bound(const key_type &_k) const
            {
                return (_M_upper_bound(_M_begin(), _M_end(), _k));
            }

            ft::pair<iterator, iterator>
            equal_range(const key_type &_k)
            {
                return (pair<iterator, iterator>(iterator(lower_bound(_k)), iterator(upper_bound(_k))));
            }

            ft::pair<const_iterator, const_iterator>
            equal_range(const key_type &_k) const
            {
                return (pair<const_iterator, const_iterator>(const_iterator(lower_bound(_k)), const_iterator(upper_bound(_k))));
            }

        protected:
            iterator _M_insert_(_Const_Base_ptr _x, _Const_Base_ptr _p, const value_type &_v)
            {
                bool _insert_left = (_x != 0 || _p == _M_end() || _M_base._M_key_compare(_KeyOfValue()(_v),  _S_key(_p)));
                _Link_type _z = _M_create_node(_v);
                
                _Rb_tree_insert_and_rebalance(_insert_left, _z, const_cast<_Base_ptr>(_p), this->_M_base._M_header);
                ++_M_base._M_node_count;
                return (iterator(_z));
            }

            _Link_type _M_copy(_Const_Link_type _x, _Link_type _p)
            {
                _Link_type _top = _M_clone_node(_x);
                _top->_M_parent = _p;

                try
                {
                    if (_x->_M_right)
                        _top->_M_right = _M_copy(_S_right(_x), _top);
                    _p = _top;
                    _x = _S_left(_x);
                    while (_x != 0)
                    {
                        _Link_type _y = _M_clone_node(_x);
                        _p->_M_left = _y;
                        _y->_M_parent = _p;
                        if (_x->_M_right)
                            _y->_M_right = _M_copy(_S_right(_x), _y);
                        _p = _y;
                        _x = _S_left(_x);
                    }
                }
                catch(...)
                {
                    _M_erase(_top);
                    std::runtime_error("copy error");
                 }
                return (_top);
            }

            void _M_erase(_Link_type _x)
            {
                 while (_x != 0)
                {
                    _M_erase(_S_right(_x));
                    _Link_type _y = _S_left(_x);
                    _M_destroy_node(_x);
                    _x = _y;
                }
            }

            iterator _M_lower_bound(_Link_type _x, _Link_type _y, const _Key &_k)
            {
                while (_x != 0)
                {
                    if (!_M_base._M_key_compare(_S_key(_x), _k))
                    {
                        _y = _x;
                        _x = _S_left(_x);
                    }
                    else
                      _x = _S_right(_x);
                }
                return (iterator(_y));
            }

            const_iterator _M_lower_bound(_Const_Link_type _x, _Const_Link_type _y, const _Key &_k) const
            {
                while (_x != 0)
                {
                    if (!_M_base._M_key_compare(_S_key(_x), _k))
                    {
                        _y = _x;
                        _x = _S_left(_x);
                    }
                    else
                      _x = _S_right(_x);
                }
                return (const_iterator(_y));
            }

            iterator _M_upper_bound(_Link_type _x, _Link_type _y, const _Key &_k)
            {
                while (_x != 0)
                {
                    if (_M_base._M_key_compare(_k, _S_key(_x)))
                    {
                        _y = _x;
                        _x = _S_left(_x);
                    }
                    else
                        _x = _S_right(_x);
                }
                return (iterator(_y));
            }

            const_iterator _M_upper_bound(_Const_Link_type _x, _Const_Link_type _y, const _Key &_k) const
            {
                while (_x != 0)
                {
                    if (_M_base._M_key_compare(_k, _S_key(_x)))
                    {
                        _y = _x;
                        _x = _S_left(_x);
                    }
                    else
                        _x = _S_right(_x);
                }
                return (const_iterator(_y));
            }

        public:
            template<typename _InputIterator>
            void insert(_InputIterator _first, _InputIterator _last)
            {
                for (; _first != _last; ++_first)
                    insert(end(), *_first);
            }

            ft::pair<iterator, bool> insert(const value_type &_v)
            {
                _Link_type _x = _M_begin();
                _Link_type _y = _M_end();
                bool _comp = true;

                while (_x != 0)
                {
                    _y = _x;
                    _comp = _M_base._M_key_compare(_KeyOfValue()(_v), _S_key(_x));
                    _x = _comp ? _S_left(_x) : _S_right(_x);
                }
                iterator _j = iterator(_y);
                if (_comp)
                {
                    if (_j == begin())
                        return (ft::pair<iterator, bool>(_M_insert_(_x, _y, _v), true));
                    else
                        --_j;
                }
                if (_M_base._M_key_compare(_S_key(_j._M_node), _KeyOfValue()(_v)))
                    return (ft::pair<iterator, bool>(_M_insert_(_x, _y, _v), true));
                return (ft::pair<iterator, bool>(_j, false));
            }

            iterator insert(const_iterator _pos, const value_type &_v)
            {
                if (_pos._M_node == _M_end())
                {
                    if (size() > 0 && _M_base._M_key_compare(_S_key(_M_rightmost()), _KeyOfValue()(_v)))
                        return (_M_insert_(0, _M_rightmost(), _v));
                    else
                        return (insert(_v).first);
                }
                else if (_M_base._M_key_compare(_KeyOfValue()(_v), _S_key(_pos._M_node)))
                {
                    const_iterator _before = _pos;
                    if (_pos._M_node == _M_leftmost())
                        return (_M_insert_(_M_leftmost(), _M_leftmost(), _v));
                    else if (_M_base._M_key_compare(_S_key((--_before)._M_node), _KeyOfValue()(_v)))
                    {
                        if (_S_right(_before._M_node) == 0)
                            return (_M_insert_(0, _before._M_node, _v));
                        else
                            return (_M_insert_(_pos._M_node, _pos._M_node, _v));
                    }
                    else
                        return (insert(_v).first);
                }
                else if (_M_base._M_key_compare(_S_key(_pos._M_node), _KeyOfValue()(_v)))
                {
                    const_iterator _after = _pos;
                    if (_pos._M_node == _M_rightmost())
                        return (_M_insert_(0, _M_rightmost(), _v));
                    else if (_M_base._M_key_compare(_KeyOfValue()(_v), _S_key((++_after)._M_node)))
                    {
                        if (_S_right(_pos._M_node) == 0)
                            return (_M_insert_(0, _pos._M_node, _v));
                        else
                            return (_M_insert_(_after._M_node, _after._M_node, _v));
                    }
                    else
                        return (insert(_v).first);
                }
                else
                    return (_pos._M_const_cast());
            }

        protected:
            void _M_erase_single(const_iterator _pos)
            {
                _Link_type _y = static_cast<_Link_type>
                                (_Rb_tree_rebalance_for_erase(const_cast<_Base_ptr>(_pos._M_node), this->_M_base._M_header));
                
                _M_destroy_node(_y);
                --_M_base._M_node_count;
            }

            void _M_erase_range(const_iterator _first, const_iterator _last)
            {
                if (_first == begin() && _last == end())
                    clear();
                else
                {
                    while (_first != _last)
                        _M_erase_single(_first++);
                }
            }
    };

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    bool operator==(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_x,
                        const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_y)
    {
      return (_x.size() == _y.size() && ft::equal(_x.begin(), _x.end(), _y.begin()));
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    bool operator<(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_x,
                    const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_y)
    {
      return (ft::lexicographical_compare(_x.begin(), _x.end(), _y.begin(), _y.end()));
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    bool operator!=(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_x,
                    const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_y)
    {
        return (!(_x == _y));
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    bool operator>(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_x,
                    const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_y)
    {
        return (_y < _x);
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    bool operator<=(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_x,
                    const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_y)
    {
        return (!(_y < _x));
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    bool operator>=(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
      const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
    {
        return (!(_x < _y));
    }

    template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
    void swap(_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_x,
                _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &_y)
    {
        _x.swap(_y);
    }
}

#endif