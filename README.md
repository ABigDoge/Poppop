# Poppop
---
### 关于数据库服务接口
使用xxxService中某个函数： xxxService::function()
具体使用方法见main.cpp中的测试

### 关于Add函数
传入的DTO是引用，所以可以修改被传入对象的ID，调用Add后，被传入对象的ID就是数据库中存的ID了。
