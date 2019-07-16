"org.eclipse.wst.validation" has been removed
把WorkSpace\.metadata\.plugins\org.eclipse.core.runtime\.settings 下的org.eclipse.wst.validation.prefs 删除就可以了 

.nowrap 一行超出省略
.nowrap-multi-2 两行超出省略
.nowrap-multi-3 三行超出省略

.nowrap{
	max-width:100%;
	overflow:hidden;
	white-space:nowrap;
	text-overflow:ellipsis
}
.nowrap-multi-2{
	display:-webkit-box;
	overflow:hidden;
	text-overflow:ellipsis;
	-webkit-box-orient:vertical;
	-webkit-line-clamp:2
}
.nowrap-multi-3{
	display:-webkit-box;
	overflow:hidden;
	text-overflow:ellipsis;
	-webkit-box-orient:vertical;
	-webkit-line-clamp:3
}

//angularJs apply()
$scope.$apply();

//angularJs 指令  render之后执行 jquery操作
app.directive('onFinishRenderFilters', function ($timeout) {
    return {
        restrict: 'A',
        link: function(scope, element, attr) {
            if (scope.$last === true) {
                $timeout(function() {
                    scope.$emit('ngBindFinished');
                },2000);
            }
        }
    };
});

$scope.$on('ngBindFinished', function (ngRepeatFinishedEvent) {
            //有问题,height为0
            //$scope.$apply();
            $('.figcaption').each(function(i){
                var pH = $(this).height();
                var $span = $("span", $(this)).eq(0);
                while ($span.outerHeight() > pH) {
                    $span.text($span.text().replace(/(\s)*([a-zA-Z0-9]+|\W)(\.\.\.)?$/, "..."));
                };
            });
    });
	
	
	
	
telnet 192.168.1.168 11112 //进入telnet页面(全黑的,证明端口可用)
netstat -an | grep 11112   //显示网络连接、路由表  

 
	
	
/********idea 快捷键***********/

Alt+ ENTER 导入包,自动修正
Alt+ INSERT 生成代码(如get,set方法,构造函数等)

Ctrl+N   查找类
Ctrl+Shift+N 查找文件

ctrl+F  当前文件查找特定内容
ctrl+Shift+F 当前项目查找包含特定内容的文件

Ctrl+r 当前文件替换特定内容
Ctrl+Shift+r 当前项目替换特定内容

双击shift 在项目的所有目录查找

Ctrl+Alt+L 格式化代码
Ctrl+Alt+O 优化导入的类和包
ctrl+Alt+T surround with

Ctrl+E 最近更改的代码
Alt+Shift+C 对比最近修改的代码

Ctrl+空格 代码提示
Ctrl+Shift+Space 自动补全代码

Ctrl+P 方法参数提示

Ctrl+Alt+Space 类名或接口名提示
Ctrl+Shift+Alt+N 查找类中的方法或变量

Alt+F7 find usage
 
Shift+F6  重构-重命名

Ctrl+Shift+先上键
Ctrl+X 删除行
Ctrl+D 复制行
Ctrl+/ 或 Ctrl+Shift+/  注释(// 或者/*...*/ )
Ctrl+J  自动代码
Ctrl+E 最近打开的文件
Ctrl+H 显示类结构图
Ctrl+Q 显示注释文档
Alt+F1 查找代码所在位置
Alt+1 快速打开或隐藏工程面板
Ctrl+Alt+ left/right 返回至上次浏览的位置 (可用,去除冲突)
Alt+ left/right 切换代码视图
Alt+ Up/Down 在方法间快速移动定位
Ctrl+Shift+Up/Down 代码向上/下移动。
F2 或Shift+F2 高亮错误或警告快速定位
 
代码标签输入完成后,按Tab,生成代码。
选中文本,按Ctrl+Shift+F7 ,高亮显示所有该文本,按Esc高亮消失。
Ctrl+W 选中代码,连续按会有其他效果
选中文本,按Alt+F3 ,逐个往下查找相同文本,并高亮显示。
Ctrl+Up/Down 光标跳转到第一行或最后一行下
Ctrl+B 快速打开光标处的类或方法 


sout +tab: system.out.print
psvm +tab: public static void main

演出模式：alt+V快捷键，弹出View视图，然后选择Enter Presentation Mode

alt+1 把鼠标焦点定位到project视图里，然后直接使用ctrl+shift+left/right来移动分割线

/*****ideal 注释模板 ***/
	--类、接口注释
	settings->Editor->code style->file and code templates
	/**
	 *${DESCRIPTION}
	 *author cash
	 *create ${YEAR}-${MONTH}-${DAY}-${TIME}
	**/
	--方法注释
	settings->Editor->code style->live templates  (自定义)  快捷键 m+ Tab   m是设置自己设置的键值
	/**
	 *@description:
	 *@author: cash
	 *@date: $date$ $time$
	**/



/********mvn 修改版本号*********/
mvn versions:set -DnewVersion=DEV-2.0-SNAPSHOT

/********mvn 依赖copy*********/
依赖copy   dependency:copy-dependencies      (target/dependency)
		   dependency:copy-dependencies -DoutputDirectory=lib 指定目录		   
		   dependency:tree

	   
# IDEA  激活服务器 docker 	
docker pull ilanyu/golang-reverseproxy
docker run -d -p 8888:8888 ilanyu/golang-reverseproxy
docker run -d -p 8888:8888 --restart=always  --name ideaServer  ilanyu/golang-reverseproxy
http://192.168.99.100:8888/

/********mysql note*********/
//lock 
-- 查询是否锁表
show OPEN TABLES where In_use > 0;
-- 查询进程
show processlist
-- 查询到相对应的进程===然后 kill    id
kill 72412;
-- 查看正在锁的事务
SELECT * FROM INFORMATION_SCHEMA.INNODB_LOCKS; 
-- 查看等待锁的事务
SELECT * FROM INFORMATION_SCHEMA.INNODB_LOCK_WAITS;

show status like '%lock%'; -- 
UNLOCK TABLES; -- 解锁

-- mysql现在已提供什么存储引擎
show engines;
-- mysql当前默认的存储引擎
show variables like '%storage_engine%';
-- 某个表用了什么引擎(
show create table ouser.u_user;
-- mysql innodb的锁是通过锁索引来实现的
-- InnoDB预设是Row-Level Lock,只有「明确」的指定主键,MySQL才会执行Row lock 否则MySQL将会执行Table Lock (将整个资料表单给锁住)
-- MYISAM 只支持表级锁,InnerDB支持行级锁
-- MYISAM类型不支持事务处理等高级处理,而InnoDB类型支持  MyISAM类型的表强调的是性能,其执行速度比InnoDB类型更快


-- MYISAM跟innodb索引都是基于B+树(也可以是hash)
主键称为主索引,其他索引是次索引
MYISAM 主索引跟次索引都指向数据记录的地址(磁盘上位置)
innodb的数据文件本身就是索引文件,主索引叶子节点的data域保存着完整的数据记录,次索引data域储存的是主键的值

叶节点保存着完整的数据记录,这种索引,称之为聚簇索引,聚簇索引使得基于主键的搜索十分高效,但是次索引需要检索两次,先获得主键,在根据主键检索

innodb索引,不应该使用过长的字段作为主键,因为所有的次索引都会引用主索引,会使次索引变得过大
而且不应该使用非单调的字段作为索引,会有频繁的分裂调整,使用自增字段就是较好的选择

table A 中 id(主键) 跟 ver是联合索引 (innodb引擎)
select id from A order by id;//很慢
select id from A order by id ver;//很快
innodb 叶节点直接存放数据,数据比较大,内存放不下,放在磁盘,id排序需要跨多个块,比较慢
联合索引不存放数据,存放的是主键id的值,文件较小,而且只是取出id,不用回行,就是在索引文件中取,较快

如果要查找的数据恰好是索引列,那么就不用去物理磁盘上找了,不用回行,称为索引覆盖


	-- 明确指定主键,并且有此笔资料,row lock
	SELECT * FROM products WHERE id='3' FOR UPDATE;
	SELECT * FROM products WHERE id='3' and type=1 FOR UPDATE;

	-- 明确指定主键,若查无此笔资料,无lock
	SELECT * FROM products WHERE id='-1' FOR UPDATE;

	-- 无主键,table lock
	SELECT * FROM products WHERE name='Mouse' FOR UPDATE;

  -- 主键不明确,table lock
	SELECT * FROM products WHERE id<>'3' FOR UPDATE;
	SELECT * FROM products WHERE id LIKE '3' FOR UPDATE;

-- A与B都对表id进行查询但查询不到记录,则A与B在查询上不会进行row锁,但A与B都会获取排它锁

-- 添加了(行级锁/表级锁)锁的数据不能被其它事务再锁定,也不被其它事务修改(修改、删除)是表级锁时,不管是否查询到记录,都会锁定表
-- 此外,如果A与B都对表id进行查询但查询不到记录,则A与B在查询上不会进行row锁
-- 但A与B都会获取排它锁,此时A再插入一条记录的话则会因为B已经有锁而处于等待中,此时B再插入一条同样的数据则会抛出Deadlock found when trying to get lock; try restarting transaction然后释放锁,此时A就获得了锁而插入成功


-- 手动开启事务
start TRANSACTION;
update u_favorite a set a.remark='test' where a.id='10018';
commit;	

//连续登陆天数查询
-- 求连续登陆天数(使用变量)
SELECT
	count(1)
FROM
	(
		SELECT
			@rownum :=@rownum + 1 rownum,
			b.*
		FROM
			(SELECT @rownum := 0) r,
			(
				SELECT
					DATEDIFF(a.create_time, '2016-01-01') DiffDays,
					MAX(a.create_time) MaxLoginDate
				FROM
					account_action a
				WHERE
					a.user_id = '1080'
          and a.company_id=10
					and a.action_type='99'
				GROUP BY
					DiffDays
        HAVING DiffDays>0
			) b
	) c
GROUP BY
	(DiffDays - rownum)  order by max(MaxLoginDate) desc limit 1

-- 求连续登陆天数(子查询)


SELECT
	count(1),
	min(MaxLoginDate),
	max(MaxLoginDate) maxLD
FROM
	(
		SELECT
			c.*, (
				SELECT
					count(1)
				FROM
					(
						SELECT
							DATEDIFF(a.create_time, '2014-01-01') DiffDays,
							MAX(a.create_time) MaxLoginDate
						FROM
							u_user_login a
						WHERE
							a.user_id = '383'
						GROUP BY
							DiffDays
					) b
				WHERE
					b.DiffDays <= c.DiffDays
			) rownum
		FROM
			(
				SELECT
					DATEDIFF(a.create_time, '2014-01-01') DiffDays,
					MAX(a.create_time) MaxLoginDate
				FROM
					u_user_login a
				WHERE
					a.user_id = '383'
				GROUP BY
					DiffDays
			) c
	) d
GROUP BY
	(DiffDays - rownum)
ORDER BY
	maxLD
	
--- 建索引的几大原则
1.最左前缀匹配原则，非常重要的原则，mysql会一直向右匹配直到遇到范围查询(>、<、between、like)就停止匹配，比如a = 1 and b = 2 and c > 3 and d = 4 如果建立(a,b,c,d)顺序的索引，d是用不到索引的，如果建立(a,b,d,c)的索引则都可以用到，a,b,d的顺序可以任意调整。
2.=和in可以乱序，比如a = 1 and b = 2 and c = 3 建立(a,b,c)索引可以任意顺序，mysql的查询优化器会帮你优化成索引可以识别的形式
3.尽量选择区分度高的列作为索引,区分度的公式是count(distinct col)/count(*)，表示字段不重复的比例，比例越大我们扫描的记录数越少
4.索引列不能参与计算，保持列“干净”，比如from_unixtime(create_time) = ’2014-05-29’就不能使用到索引，原因很简单，b+树中存的都是数据表中的字段值，但进行检索时，需要把所有元素都应用函数才能比较，显然成本太大。所以语句应该写成create_time = unix_timestamp(’2014-05-29’);
5.尽量的扩展索引，不要新建索引。比如表中已经有a的索引，现在要加(a,b)的索引，那么只需要修改原来的索引即可
	
	
-- ideal vm配置
-Dglobal.config.path=C:\svvn\env\ds-trunk -Xms500m -Xmx800m -XX:MaxPermSize=512m
	

----日志查看  匹配
cat error.*|grep -5 '62158420678887307341184'
cat error.*|grep -5 '62158420678887307341184'|grep '增加'
cat info.log|grep -5 --color=auto 170105349961845010

----获得进程号
ps -ef|grep ac-sms-api-provider-xuanwu.jar|gawk '$0 !~/grep/ {print $2}'|tr -s '\n'''
--kill
kill -9 $(ps -ef|grep ac-sms-api-provider-xuanwu.jar|gawk '$0 !~/grep/ {print $2}'|tr -s '\n''')
java -jar ac-sms-api-provider-xuanwu.jar > xuanwu.log &


-- 唯一索引
  去重处理：调用方生成唯一指令,指令+来源 作为组合唯一索引
  insert or update：先insert,捕获违反唯一性约束异常,没有异常就做update操作
  分布式锁：zk,redis,db   唯一索引,能insert成功的有操作权限,能创建文件成功的有操作权限
  
 
-- soa接口,参数丢失问题
hessian接口,序列化时,如果子类中与父类中有重名属性,属性值会丢失
http://tianya23.blog.51cto.com/1081650/582256/
jdk的序列化不会


-- 数据库AES加密
select (CONCAT('@%^*',TO_BASE64(AES_ENCRYPT(18801627983,'1fi;qPa7utddahWy'))));
select  AES_DECRYPT(FROM_BASE64(SUBSTRING(mobile,5)),'1fi;qPa7utddahWy')  FROM `u_user` a where a.username='dsadmin';   
		   
-- lombok

	@Data ：注解在类上；提供类所有属性的 getting 和 setting 方法,此外还提供了equals、canEqual、hashCode、toString 方法

	@Setter：注解在属性上；为属性提供 setting 方法

	@Getter：注解在属性上；为属性提供 getting 方法

	@Log4j ：注解在类上；为类提供一个 属性名为log 的 log4j 日志对象

	@NoArgsConstructor：注解在类上；为类提供一个无参的构造方法

	@AllArgsConstructor：注解在类上；为类提供一个全参的构造方法

	@NonNull：注解在参数上 如果该参数为null 会throw new NullPointerException(参数名);

	@Cleanup：注释在引用变量前：自动回收资源 默认调用close方法

　　@Cleanup("dispose") org.eclipse.swt.widgets.CoolBar bar = new CoolBar(parent, 0);

　　@Cleanup InputStream in = new FileInputStream(args[0]);

　　@Cleanup OutputStream out = new FileOutputStream(args[1]);

	@Builder：注解在类上；为类提供一个内部的Builder

#防火墙设置
开启： chkconfig iptables on 
关闭： chkconfig iptables off 
2) 即时生效,重启后失效 
开启： service iptables start 
关闭： service iptables stop 
需要说明的是对于Linux下的其它服务都可以用以上命令执行开启和关闭操作。 
在开启了防火墙时,做如下设置,开启相关端口, 
修改/etc/sysconfig/iptables 文件,添加以下内容： 
-A RH-Firewall-1-INPUT -m state --state NEW -m tcp -p tcp --dport 80 -j ACCEPT 
-A RH-Firewall-1-INPUT -m state --state NEW -m tcp -p tcp --dport 22 -j ACCEPT	


/**************** git ******************/
	git init //目录变成Git可以管理的仓库
	git status  //仓库当前的状态
	git diff  //差异
	git add	  //增加
		git add -A  //提交所有变化
		git add -u  //提交被修改(modified)和被删除(deleted)文件,不包括新文件(new)
		git add .   //提交新文件(new)和被修改(modified)文件,不包括被删除(deleted)文件
	git commit -m 'xxx' //提交
	git log //提交日志   git log --pretty=oneline
	
	git checkout . //放弃所有修改的文件
	git reset --hard HEAD^  //版本回退    HEAD是当前版本,HEAD^上一版本 HEAD^^上上版本  HEAD~100上100个版本
	git reset --hard 3628164 //回退到指定版本,版本号可以不用写全
	
	git reset HEAD file可以把暂存区的修改撤销掉(unstage),重新放回工作区
	git reset命令既可以回退版本,也可以把暂存区的修改回退到工作区。当我们用HEAD时,表示最新的版本
	
	########## git 放弃修改 ##########
	未使用git add缓存代码： git checkout -- filename   放弃所有的文件修改可以使用 git checkout . ,但是不会删除新建的文件,因为没有进git,需要收到删除
	使用了git add缓存了代码：git reset HEAD filename 放弃指定文件的缓存,放弃所有的缓存可以使用 git reset HEAD .
	使用git commit 提交了代码：使用 git reset --hard HEAD^ (git reset --hard "HEAD^")来回退到上一次commit的状态,可以用来回退到任意版本：git reset --hard  commitid  (commitid使用git log查看)
	
    	
	
	git reflog  //记录每一次命令,命令历史
		文件往Git版本库里添加的时候,是分两步执行的：
	第一步是用git add把文件添加进去,实际上就是把文件修改添加到暂存区；
	第二步是用git commit提交更改,实际上就是把暂存区的所有内容提交到当前分支
	git checkout -- file  //把文件在工作区的修改全部撤销 ,文件回到最近一次git commit或git add时的状态
	

	git rm   //删除文件
	git rm   之后,从版本库恢复, git checkout --file	
	关联一个远程库,使用命令git remote add origin git@server-name:path/repo-name.git
	关联后,使用命令git push -u origin master第一次推送master分支的所有内容
	
	git clone git@github.com:michaelliao/gitskills.git //从远程库克隆
	git clone https://github.com/alibaba/druid.git
	
	
	git checkout -t 本地建立一个和远程分支名字一样的分支
	git checkout branch-name //切换分支
	git checkout 命令加上-b参数表示创建并切换  //git checkout -b dev  创建一个dev分支
	git branch //命令查看当前分支 ,当前分支前面会标一个*号
	
	git merge 命令用于合并指定分支到当前分支  //git merge dev Fast-forward  “快进模式”,也就是直接把master指向dev的当前提交
	
	git branch -d <name> //删除本地分支
	git branch -D <name> //强行删除分支,还没有合并
	
	git merge --no-ff dev //"merge with no-ff"   禁用Fast forward
	
	git stash //可以把当前工作现场“储藏”起来,等以后恢复现场后继续工作
	
	git stash list //查看stash的内容
	
	git stash apply stash@{0} //恢复stash的内容 
	
	//远程克隆 
	git remote //查看远程仓库信息
	git remote -v //详细信息
	
	git push origin master //推送分支
	
	git tag <name>  //打一个标签
	git tag //查看所有标签//给已经commit的打标签
	git log --pretty=oneline --abbrev-commit  //查看提交记录
	git tag v0.9  6224937 //给对应版本打标签
	git tag -a v0.1 -m "version 0.1 released" 3628164  // -m 说明文字	
	git tag -d v0.1 //删除标签
	git push origin v1.0 //推送标签到远程
	git push origin --tags //一次性推送全部尚未推送到远程的本地标签	
	.gitignore //忽略文件
	
	
	git@github.com:shouyinsun/Stupid-human.git
	
	git@git.ppdaicorp.com:ppdai-uc/ppdai-ac-pwr.git
	
	//保证 ~/.ssh 文件夹存在,并且没有任何文件 生成默认文件
	ssh-keygen -t rsa -C "442620332@qq.com"
	
	//测试ssh keys是否设置成功。
    ssh -T git@github.com
	
	
	TortoiseGit  需要加载putty密钥   否则就会在clone的时候提示要输入password密码,引入私钥之后就不需要什么密码了
	
	consul agent -dev  //consul win 下 dos启动
	
	/************* linux ************/	
	netstat
	-a (all)显示所有选项,默认不显示LISTEN相关
	-t (tcp)仅显示tcp相关选项
	-u (udp)仅显示udp相关选项
	-n 拒绝显示别名,能显示数字的全部转化成数字
	-l 仅列出有在 Listen (监听) 的服務状态

	-p 显示建立相关链接的程序名
	-r 显示路由信息,路由表
	-e 显示扩展信息,例如uid等
	-s 按各个协议进行统计
	-c 每隔一个固定时间,执行该netstat命令
	
	ESTABLISHED 表示正在通信,TIME_WAIT 表示主动关闭,CLOSE_WAIT 表示被动关闭
	
	df
	-a或--all：包含全部的文件系统
	--block-size=<区块大小>：以指定的区块大小来显示区块数目
	-h以可读性较高的方式来显示信息
	-H或--si：与-h参数相同 
	-i或--inodes：显示inode的信息
	-k或--kilobytes：指定区块大小为1024字节
	-l或--local：仅显示本地端的文件系统
	-m或--megabytes：指定区块大小为1048576字节
	--no-sync：在取得磁盘使用信息前不要执行sync指令此为预设值；
	-P或--portability：使用POSIX的输出格式
	--sync：在取得磁盘使用信息前
	--help：显示帮助
	
	du -sh *
	-h：以人类可读的方式显示
　　-a：显示目录占用的磁盘空间大小 还要显示其下目录和文件占用磁盘空间的大小
　　-s：显示目录占用的磁盘空间大小 不要显示其下子目录和文件占用的磁盘空间大小
　　-c：显示几个目录或文件占用的磁盘空间大小还要统计它们的总和

	/**抓包***/
	tcpdump -vv -Ss 0 -i eth0 port 9080 -w xw-post-9080.pcap
	tcpdump -vv -Ss 0  host 222.73.44.38  -w tc-38.pcap
	
	/**线程数**/
	pstree -p 17156 | wc -l
	
	/**5s刷新一次**/
	watch -n 5 -d 'pstree -p 43753 |wc -l' 
	
	
	#统计80端口连接数
	netstat -nat|grep -i "80"|wc -l

	#统计httpd协议连接数
	ps -ef|grep httpd|wc -l

	#统计已连接上的,状态为“established
	netstat -na|grep ESTABLISHED|wc -l
	
	#统计TIME_WAIT
	watch -n 5 -d 'netstat -na|grep TIME_WAIT|wc -l'

	#查出哪个IP地址连接最多
	netstat -na|grep ESTABLISHED|awk {print $5}|awk -F: {print $1}|sort|uniq -c|sort -r +0n
	
	netstat -na | awk '{print $5}' | sed -n '/[0-9]*\.[0-9]*\.[0-9]*\.[0-9]*\:.*/p' | cut -d':' -f1 | sort | uniq -c | sort -nr | head -10
	
	/**统计各状态的计数**/
	netstat -n | awk '/^tcp/ {++S[$NF]} END {for(a in S) print a, S[a]}' 
	
	
	/**window下统计状态个数**/
	netstat -an|find "ESTABLISHED" /c 
	netstat -an|find "CLOSE_WAIT" /c 
	netstat -an|find "TIME_WAIT" /c 
	
	#获取占用CPU资源最多的10个进程：
	ps aux|head -1;ps aux|grep -v PID|sort -rn -k +3|head
	#获取占用内存资源最多的10个进程：
	ps aux|head -1;ps aux|grep -v PID|sort -rn -k +4|head
	
	
	-XX:+HeapDumpOnOutOfMemoryError -XX:HeapDumpPath=/www/websit/dump -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -Xloggc:/www/website/dump/heap_trace.tx
	java -XX:+HeapDumpOnOutOfMemoryError -XX:HeapDumpPath=/usr/local/service -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -Xloggc:/usr/local/service/heap_trace.tx -jar ac-riskcontrol-service.jar > ac-riskcontrol-service.log &

	
	sudo dmesg -r | grep "(java)"
	
	
	查看当前cpu 内存
	top 
	htop
	
	#查看cpu
	cat /proc/cpuinfo
	lscpu
	#查看内存
	
	
	# 反选删除
	# shopt -s extglob   (打开extglob模式)
	# rm -fr !(file1)
	
	/**redis client**/
	redis-cli -h 192.168.212.170 -p 7000 
	
	js中 点语法时,对象名字不能是变量,但方括号语法没有该限制,名字可以是任意表达式的结果
	cash={"name":"xuchao","telphone":"15121002698"};var t="name"; alert(cash.name);alert(cash["name"]);alert(cash[t]);
	
	/**查看端口占用**/ 
	netstat -ano|findstr "9091" 知道pid,资源管理器中干掉 //window 
	netstat -na|grep -i "9080"|grep ESTABLISHED|wc -l
	
	/** os版本 **/
	cat /proc/version 
	cat /etc/os-release
	
	/***磁盘清理,deleted**/
	lsof | grep deleted
	
	/**链接 ln    -s软链***/
	ln -s /root/software/nodejs/node-v4.4.4-linux-x64/bin/node /usr/local/bin/node
	ln -s /root/software/nodejs/node-v4.4.4-linux-x64/bin/npm /usr/local/bin/npm
	
	/**find & locate **/
	find / -name 'redis_cluster*'
	locate redis_cluster
	
	/**文件夹/子文件夹赋权**/
	chmod -R 777 name
	
	
	#查看内存占用进程
	ps -aux | sort -k4nr | head -K
	
	如果是10个进程,K=10
	说明：ps -aux中(a指代all——所有的进程,u指代userid——执行该进程的用户id,x指代显示所有程序,不以终端机来区分)
	ps -aux的输出格式如下：
	USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
	sort -k4nr中(k代表从第几个位置开始,后面的数字4即是其开始位置,结束位置如果没有,则默认到最后；n指代numberic sort,根据其数值排序；r指代reverse,这里是指反向比较结果,输出时默认从小到大,反向后从大到小。)。本例中,可以看到%MEM在第4个位置,根据%MEM的数值进行由大到小的排序。
	head -K(K指代行数,即输出前几位的结果)
	
	
	
	/**秒杀超库存 AND >0 条件 通过返回影响行数 区别**/
	update SecKillGoods g set g.remainNum = g.remainNum - 1 where g.id=10000 and g.remainNum>0
	
	/****Innodb 与 MyISAM 区别****/
	Innodb引擎:支持事务、支持故障恢复、支持行级锁、支持外键、不支持全文索引、不保存行数,select count(1) 是全表扫描
	MyIASM引擎:MySql的默认引擎、不支持事务、写操作,是锁全表、支持全文索引、保存行数(适用 读多写少、不需要事务)
	

	大容量的数据集时趋向于选择Innodb。因为它支持事务处理和故障的恢复
	Innodb可以利用数据日志来进行数据的恢复。主键的查询在Innodb也是比较快的
	
	
	#nginx 
	nginx -s reload  ：修改配置后重新加载生效
	nginx -s reopen  ：重新打开日志文件
	nginx -t -c /path/nginx.conf 测试nginx配置文件是否正确

	关闭nginx：
	nginx -s stop  :快速停止nginx
			 quit  ：完整有序的停止nginx

	其他的停止nginx 方式：
	ps -ef | grep nginx

	kill -QUIT 主进程号     ：从容停止Nginx
	kill -TERM 主进程号     ：快速停止Nginx
	pkill -9 nginx          ：强制停止Nginx


	启动nginx:
	nginx -c /path/nginx.conf
	
	
	#develop cassandra
	cassandra 192.168.212.170:9042
	./cassandra 
	./cqlsh
	
	describe keyspaces;
	describe tables;
	
	
	#druid
		#启动
		nohup bin/supervise -c conf/supervise/quickstart.conf > quickstart.log&
		#停止
		bin/service --down 
		#重启
		bin/service --restart ${服务名}
		
		#coordinator
		http://192.168.211.58:8081
		#broker 查询节点
		http://192.168.211.58:8082/druid/v2
		#historical 历史节点
		http://192.168.211.58:8083/druid/v2
		#overlord 统治节点
		http://192.168.211.58:8090/console.html
		#pivot webUI
		http://192.168.211.58:9095
		#tranquility-server 实时写入服务
		http://192.168.211.58:8200/v1/post/datasource
		
		

	
	
	#编码格式
	ASCII：  0-9 字母,符号等 只有127个字符 
	Unicode：把所有语言都统一到一套编码里,最常用的是用两个字节表示一个字符(如果要用到非常偏僻的字符,就需要4个字节)
	UTF-8: "可变长编码",UTF-8 编码把一个Unicode字符根据不同的数字大小编码成1-6个字节,常用的英文字母被编码成1个字节,汉字通常是3个字节,只有很生僻的字符才会被编码成4-6个字节
	
	ASCII编码实际上可以被看成是UTF-8编码的一部分
	在计算机内存中,统一使用Unicode编码,当需要保存到硬盘或者需要传输的时候,就转换为UTF-8编码
	
	# OuterClass.this
	实际上我们代指当前类对象的this是个简写形式,完整的形式就是 类名字.this
	对当前类对象的引用，可以用xxClass.this，也可以直接用this。
    内部内对当前外部类OuterClass的类对象引用就只能用OuterClass.this，不能用this


    # UML 类图
    虚线箭头指向依赖；
	实线箭头指向关联；
	虚线三角指向接口；
	实线三角指向父类；
	空心菱形能分离而独立存在，是聚合；
	实心菱形精密关联不可分，是组合；


	java -D 配置系统属性
	java -Dkey=value 参数优先级最高,会覆盖项目中配置的此项

   

    # JVM 命令
    jmap （JVM Memory Map） 命令用于生成堆dump文件	

    	jmap -dump:live,format=b,file=dump.hprof pid  #生成dump文件,可以使用 JvisualVm 打开
    	jmap -heap pid  		 #打印heap的概要信息、GC使用的算法 
    	jmap -finalizerinfo pid  #打印等待回收的对象信息
    	jmap -histo  pid         #打印堆的对象统计 包括对象数、内存大小
    	jmap -permstat pid       #Java堆内存的永久区的类加载器的智能统计信息


    jstat (JVM statistics Monitoring)是用于监视虚拟机运行时状态信息的命令 可以显示出虚拟机进程中的类装载、内存、垃圾收集、JIT编译等运行数据

    	jstat -class pid         #监视类装载、卸载数量、总空间以及耗费的时间
    	jstat -gc pid            #垃圾回收堆的行为统计
    	jstat -gccapacity pid    #同gc，会有堆各区域使用到的最大、最小空间
    	jstat -gccause  pid      #各空间使用百分比,最近两次垃圾回收事件的原因

    jstack 用于生成java虚拟机当前时刻的线程快照 ,栈信息
    线程快照是当前java虚拟机内每一条线程正在执行的方法堆栈的集合 生成线程快照的主要目的是定位线程出现长时间停顿的原因 如线程间死锁、死循环、请求外部资源导致的长时间等待等

    	jstack pid               #栈信息
    	jstack -l pid            #除堆栈外，显示关于锁的附加信
    	

	
	# 查看mysql wait_timeout
	show global variables like 'wait_timeout';

	#查看版本
	select version();

	5.6.29-76.2-log

	#curl post
	curl couponcenter.shengpay.com/coupon-center/coupon/v1/queryCouponAmount -X POST -H "Content-Type:application/json" -d '"app":"WIFI","merchantNo":"11842095","nonceStr":"bf0b7b4d","requestTime":"2018-11-02 10:48:27","sign":"hKDwfzdXZOWL/y2ATpyAoak7fBZ65LYrXNiaUIuP77SzXIk85UYryvU9sz8OVxijQWwUQ4nFV2o76yWtZk9uh39YvQ5OhwJ9xNWWUeIKXMGRE/7wZCInA3n+ZEPl9gc91YM5H9GdiGzdxg0T9yohEmLdkGEL68mT16yxt1KOZYJuU9qRvghuKzvTzEFolfCNHUuidvEt9v4ZYxYJhJZnxSSdbWhta7uM/DD8EaNu4oMj1fQqIqIqeMMgy7PA4j7J1OdmdFv6QlvAwlbzmZ7H125KRPwq/PY9ZQZbfGGS0DaKCyO/iYJVfKykLjs+MA3ZFv2V6SPKmBDrG1DkziJ5OQ==","uhId":"kttnsvtuqgncab8702b646484b3cee7f"'
	

	## 添加 .gitignore
	git rm -r --cached . // 删除本地缓存
	git add . // 添加要提交的文件
	git commit -m 'update .gitignore' // 更新本地的缓存



	## redis 设置密码(不重启,重启不恢复默认),进入各个实例进行设置
	config set masterauth passwd123 
    config set requirepass passwd123 
    config rewrite 
    
    ## config set requirepass "" //取消密码



    ### idea lombok 找不到方法错误
    https://blog.csdn.net/xzp_12345/article/details/80268834
    
    
    ### lua 脚本,Lua是从1开始排序
    ###redis 抢红包
	-- 脚本：尝试获得红包,如果成功,则返回json字符串,如果不成功,则返回空
	-- 参数：红包队列名 hongBaoList, 已消费的队列名 hongBaoConsumedList,去重的Map名 hongBaoConsumedMap,用户ID
	-- 返回值：nil 或者 json字符串,包含用户ID：userId,红包ID：id,红包金额：money
	--  jedis.eval(getScript(), 4, hongBaoList, hongBaoConsumedList, hongBaoConsumedMap, "" + j)
	if redis.call('hexists', KEYS[3], KEYS[4]) ~= 0 then
	      return nil
	      else
	      -- 先取出一个小红包
	      local hongBao = redis.call('rpop', KEYS[1])
	      -- hongbao ： {"Money":9,"Id":8}
	          if hongBao then
	              local x = cjson.decode(hongBao)
	              -- 加入用户ID信息
	              x['userId'] = KEYS[4]
	              local re = cjson.encode(x)
	              -- 把用户ID放到去重的set里
	              redis.call('hset', KEYS[3], KEYS[4], KEYS[4])
	              -- 把红包放到已消费队列里
	              redis.call('lpush', KEYS[2], re)
	          return re;
	          end
	      end
	return nil


	### script load 脚本缓存,通过脚本内容的SHA1摘要来执行脚本
	redis 127.0.0.1:6379> SCRIPT LOAD "return 'hello moto'"
	"232fd51614574cf0867b83d384a5e898cfd24e5a"
 
	redis 127.0.0.1:6379> EVALSHA "232fd51614574cf0867b83d384a5e898cfd24e5a" 0
	"hello moto"
