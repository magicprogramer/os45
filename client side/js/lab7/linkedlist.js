function Linkedlist()
{
    return {
        data:Array(),
        Enqueue:function(value){
            if (!isFinite(value))
            {
                throw "not a number";
            }
            var obj = {
                val:value
            };
            if (this.data.length == 0)
            {
              this.data.push(obj);  
            }
            else if (this.data[0].val > value)
            {
                this.data.unshift(obj);
            }
            else
            {
                throw "can't insert value";
            }
        },
        Insert:function(value, place) //insert value into place (zero based)
        {
            var obj = {
                val:value
            };
            if (this.data.length == 0)
            {
                if (place == 0)
                {
                    this.Enqueue(value);
                }else
                {
                    throw "position doesn't exist";

                }
                return ;
            }
            if (place == 0)
            {
                if (this.data[0].val > value)
                {
                    this.data.unshift(obj);
                }
                else
                {
                    throw "can't insert number at the beginning number is greater than the first number";
                }
            }
            else if (place > this.data.length)
            {
                throw "position doesn't exist";
            }
            else if (place == this.data.length)
            {
                if (this.data[this.data.length - 1].val < value)
                {
                    this.data.push(obj);
                }
                else
                {
                    throw "can't insert number at the end number is smaller than the second number";
                }
            }
            else
            {
                for (var j = 0; j < this.data.length - 1; j ++)
                {
                    if (this.data[j].val < value && this.data[j + 1].val > value)
                    {
                       // console.log(j);
                        if (j == place - 1)
                        {
                            this.data.splice(place, 0, obj);
                            return ;
                        }
                    }
                }
                throw "can't insert number";
            }
        },
        Pop:function(){
            if (this.data.length)
            {
                return this.data.pop();
            }
            else
            {
                throw "list is empty";
            }
        },
        Remove:function(value, place)
        {
            if (this.data.length >= place || this.data[place] != value)
            {
                throw "can't remove this element doesn't exist";
            }
            else
            {
                this.data.splice(place, 1);
            }

        },
        Display:function()
        {
            for (var j = 0; j < this.data.length; j ++)
            {
                console.log(this.data[j].val);
            }
            console.log("------\n");
        },
        Dequeue:function()
        {
            return this.data.shift();
        }
        


    }
}
var list = new Linkedlist();
list.Insert(2, 0); // [1]
list.Insert(1, 0); //[1, 2]
list.Display();
list.Insert(10, 2); //[1, 2, 10]
list.Insert(9, 2); //[1, 2, 9, 10]
list.Pop(); //[1, 2, 9]
list.Dequeue(); //[2, 9]
list.Display();